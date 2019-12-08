
#include "Cluster.h"

Cluster::Cluster(Objeto* colisao) : _colisao(colisao), Objeto("cluster", false, colisao->material){}

void Cluster::adicionarObjeto(Objeto *obj)
{
    _objetosInternos.emplace_back(obj);
}

tuple<Ponto *, Objeto *> Cluster::IntersecaoReta(Ponto *pP0, const Vetor &pV0)
{
    auto pontosCol = _colisao->IntersecaoReta(pP0, pV0);
    Ponto* p_int = nullptr;
    Ponto* p_int_prox = nullptr;
    double dist = 0, dist_nova;
    Objeto* p_obj = nullptr;
    Objeto* p_obj_prox = nullptr;
    if(std::get<0>(pontosCol) != nullptr) {
        for(auto &obj : _objetosInternos) {

            tie(p_int, p_obj) = obj->IntersecaoReta(pP0, pV0);
            if(p_int != nullptr && ((p_int_prox == nullptr && (dist_nova = biblioteca::distanciaEntrePontos(p_int, pP0)) > 0) ||
            (dist > (dist_nova = biblioteca::distanciaEntrePontos(p_int, pP0))))) {
                dist = dist_nova;
                p_int_prox = p_int;
                p_obj_prox = p_obj;
            }
        }

        if (p_int_prox != nullptr) {
            return make_pair(p_int_prox, p_obj_prox);
        }
        //return make_pair(std::get<0>(pontosCol), this);
    }
    return make_pair(nullptr, nullptr);
}

Ponto *Cluster::PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0)
{
    if(_colisao->PrimeiraIntersecao(pP0, pVetor0) != nullptr) {
        for(auto &obj : _objetosInternos) {
            auto ponto = obj->PrimeiraIntersecao(pP0, pVetor0);
            if(ponto != nullptr) {
                return ponto;
            }
        }
    }
    return nullptr;
}

void Cluster::aplicarTransformacao(vector<Matriz> &pMatrizesTransf)
{
    _colisao->aplicarTransformacao(pMatrizesTransf);
    for(auto &obj : _objetosInternos) {
        obj->aplicarTransformacao(pMatrizesTransf);
    }
}

void Cluster::mudaCoodCamera(Camera *camera)
{
    _colisao->mudaCoodCamera(camera);
    for(auto &obj : _objetosInternos) {
        obj->mudaCoodCamera(camera);
    }
}

void Cluster::mudaCoodMundo(Camera *camera)
{
    _colisao->mudaCoodMundo(camera);
    for(auto &obj : _objetosInternos) {
        obj->mudaCoodMundo(camera);
    }
}

Vetor Cluster::calcularNormal(Ponto *p)
{
    return _colisao->calcularNormal(p);
}

Objeto *Cluster::aplicarEspelhamento(vector<Matriz> &pMatrizesTransf)
{
    return nullptr;
}

Ponto *Cluster::getCentro()
{
    return _colisao->getCentro();
}

tuple<Ponto, Ponto> Cluster::Limites()
{
    Ponto max;
    Ponto min;
    Ponto novoMax;
    Ponto novoMin;
    tie(max, min) = _objetosInternos[0]->Limites();
    for(int i = 1; i < _objetosInternos.size(); i ++) {
        tie(novoMax, novoMin) = _objetosInternos[i]->Limites();
        if(novoMax.x > max.x){
            max.x = novoMax.x;
        }
        if(novoMax.y > max.y){
            max.y = novoMax.y;
        }
        if(novoMax.z > max.z){
            max.z = novoMax.z;
        }
        if(novoMin.x < min.x){
            min.x = novoMin.x;
        }
        if(novoMin.y < min.y){
            min.y = novoMin.y;
        }
        if(novoMin.z < min.z){
            min.z = novoMin.z;
        }
    }
    return make_tuple(max, min);
}
