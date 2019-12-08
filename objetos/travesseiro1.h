const int travesseiro1_num_vertices = 96;
const int travesseiro1_num_faces = 188;

float travesseiro1_vertices[] = { 
-2.001469, 0.936109, 3.628977,
-1.966363, 0.974746, 3.678724,
-2.022449, 0.969570, 3.649958,
-1.981261, 0.941271, 3.651140,
-2.009268, 0.938686, 3.636776,
-1.989641, 0.943810, 3.657726,
-1.978852, 0.972162, 3.679877,
-1.968376, 0.955453, 3.669400,
-1.980568, 0.953794, 3.670582,
-2.016969, 0.950968, 3.644477,
-1.999439, 0.970262, 3.669318,
-1.995062, 0.952457, 3.663148,
-2.024927, 1.283843, 3.737288,
-2.074674, 1.322480, 3.702182,
-2.081014, 1.278666, 3.708522,
-2.034250, 1.303136, 3.735276,
-2.037416, 1.281258, 3.738441,
-2.046134, 1.299844, 3.736147,
-2.080517, 1.314733, 3.708025,
-2.052510, 1.317318, 3.722389,
-2.058990, 1.309829, 3.727075,
-2.058003, 1.279358, 3.727882,
-2.082844, 1.298651, 3.710352,
-2.060628, 1.298506, 3.728714,
-2.340880, 0.936109, 3.289566,
-2.361861, 0.969570, 3.310547,
-2.390627, 0.974746, 3.254460,
-2.348679, 0.938686, 3.297365,
-2.363044, 0.941271, 3.269358,
-2.369629, 0.943810, 3.277737,
-2.381221, 0.970262, 3.287536,
-2.356380, 0.950968, 3.305066,
-2.375051, 0.952457, 3.283159,
-2.381304, 0.955453, 3.256472,
-2.391780, 0.972162, 3.266949,
-2.382485, 0.953794, 3.268665,
-2.414085, 1.322480, 3.362771,
-2.449191, 1.283843, 3.313024,
-2.420425, 1.278666, 3.369111,
-2.434293, 1.317318, 3.340607,
-2.419928, 1.314733, 3.368614,
-2.438978, 1.309829, 3.347087,
-2.450344, 1.281258, 3.325513,
-2.447179, 1.303136, 3.322347,
-2.448050, 1.299844, 3.334231,
-2.422256, 1.298651, 3.370941,
-2.439785, 1.279358, 3.346100,
-2.440617, 1.298506, 3.348725,
-1.892187, 0.977520, 3.519695,
-1.885847, 1.021334, 3.513355,
-1.857081, 1.016157, 3.569442,
-1.886344, 0.985267, 3.513852,
-1.871979, 0.982682, 3.541858,
-1.867294, 0.990171, 3.535379,
-1.866487, 1.020642, 3.536366,
-1.884017, 1.001349, 3.511525,
-1.865655, 1.001494, 3.533741,
-1.859093, 0.996864, 3.560118,
-1.855928, 1.018742, 3.556953,
-1.858221, 1.000156, 3.548235,
-1.965392, 1.363891, 3.592900,
-1.915645, 1.325254, 3.628006,
-1.944411, 1.330430, 3.571919,
-1.943229, 1.358729, 3.613107,
-1.957593, 1.361314, 3.585101,
-1.936643, 1.356190, 3.604728,
-1.914492, 1.327838, 3.615517,
-1.924968, 1.344547, 3.625993,
-1.923787, 1.346206, 3.613801,
-1.949892, 1.349032, 3.577400,
-1.925051, 1.329738, 3.594930,
-1.931221, 1.347543, 3.599307,
-2.231598, 0.977520, 3.180284,
-2.281345, 1.016157, 3.145178,
-2.225258, 1.021334, 3.173944,
-2.253762, 0.982682, 3.160076,
-2.225755, 0.985267, 3.174441,
-2.247282, 0.990171, 3.155391,
-2.268856, 1.018742, 3.144025,
-2.272022, 0.996864, 3.147190,
-2.260138, 1.000156, 3.146318,
-2.223428, 1.001349, 3.172113,
-2.248269, 1.020642, 3.154583,
-2.245644, 1.001494, 3.153752,
-2.304803, 1.363891, 3.253489,
-2.283823, 1.330430, 3.232508,
-2.339909, 1.325254, 3.203742,
-2.297004, 1.361314, 3.245690,
-2.325011, 1.358729, 3.231325,
-2.316632, 1.356190, 3.224740,
-2.306833, 1.329738, 3.213148,
-2.289303, 1.349032, 3.237988,
-2.311210, 1.347543, 3.219318,
-2.337897, 1.344547, 3.213065,
-2.327420, 1.327838, 3.202589,
-2.325704, 1.346206, 3.211884,

};

int travesseiro1_faces[] = { 
61,  1, 50,
85, 49, 74,
36, 60, 84,
14, 25,  2,
37, 73, 26,
 3,  4,  0,
 3,  8,  5,
 6,  7,  1,
 6, 11,  8,
 9, 10,  2,
 9,  5, 11,
 5,  8, 11,
15, 16, 12,
15, 20, 17,
18, 19, 13,
18, 23, 20,
21, 22, 14,
21, 17, 23,
17, 20, 23,
27, 28, 24,
27, 32, 29,
30, 31, 25,
30, 35, 32,
33, 34, 26,
33, 29, 35,
29, 32, 35,
39, 40, 36,
39, 44, 41,
42, 43, 37,
42, 47, 44,
45, 46, 38,
45, 41, 47,
41, 44, 47,
51, 52, 48,
51, 56, 53,
54, 55, 49,
54, 59, 56,
57, 58, 50,
57, 53, 59,
53, 56, 59,
63, 64, 60,
63, 68, 65,
66, 67, 61,
66, 71, 68,
69, 70, 62,
69, 65, 71,
65, 68, 71,
75, 76, 72,
75, 80, 77,
78, 79, 73,
78, 83, 80,
81, 82, 74,
81, 77, 83,
77, 80, 83,
87, 88, 84,
87, 92, 89,
90, 91, 85,
90, 95, 92,
93, 94, 86,
93, 89, 95,
89, 92, 95,
 0, 27, 24,
 4, 31, 27,
 9, 25, 31,
12,  6,  1,
16, 10,  6,
21,  2, 10,
36, 18, 13,
40, 22, 18,
45, 14, 22,
26, 42, 37,
34, 46, 42,
30, 38, 46,
24, 75, 72,
28, 79, 75,
33, 73, 79,
84, 39, 36,
88, 43, 39,
93, 37, 43,
74, 90, 85,
82, 94, 90,
78, 86, 94,
72, 51, 48,
76, 55, 51,
81, 49, 55,
60, 87, 84,
64, 91, 87,
69, 85, 91,
50, 66, 61,
58, 70, 66,
54, 62, 70,
48,  3,  0,
52,  7,  3,
57,  1,  7,
13, 63, 60,
19, 67, 63,
15, 61, 67,
72,  0, 24,
61, 12,  1,
85, 62, 49,
36, 13, 60,
14, 38, 25,
37, 86, 73,
 3,  5,  4,
 3,  7,  8,
 6,  8,  7,
 6, 10, 11,
 9, 11, 10,
 9,  4,  5,
15, 17, 16,
15, 19, 20,
18, 20, 19,
18, 22, 23,
21, 23, 22,
21, 16, 17,
27, 29, 28,
27, 31, 32,
30, 32, 31,
30, 34, 35,
33, 35, 34,
33, 28, 29,
39, 41, 40,
39, 43, 44,
42, 44, 43,
42, 46, 47,
45, 47, 46,
45, 40, 41,
51, 53, 52,
51, 55, 56,
54, 56, 55,
54, 58, 59,
57, 59, 58,
57, 52, 53,
63, 65, 64,
63, 67, 68,
66, 68, 67,
66, 70, 71,
69, 71, 70,
69, 64, 65,
75, 77, 76,
75, 79, 80,
78, 80, 79,
78, 82, 83,
81, 83, 82,
81, 76, 77,
87, 89, 88,
87, 91, 92,
90, 92, 91,
90, 94, 95,
93, 95, 94,
93, 88, 89,
 0,  4, 27,
 4,  9, 31,
 9,  2, 25,
12, 16,  6,
16, 21, 10,
21, 14,  2,
36, 40, 18,
40, 45, 22,
45, 38, 14,
26, 34, 42,
34, 30, 46,
30, 25, 38,
24, 28, 75,
28, 33, 79,
33, 26, 73,
84, 88, 39,
88, 93, 43,
93, 86, 37,
74, 82, 90,
82, 78, 94,
78, 73, 86,
72, 76, 51,
76, 81, 55,
81, 74, 49,
60, 64, 87,
64, 69, 91,
69, 62, 85,
50, 58, 66,
58, 54, 70,
54, 49, 62,
48, 52,  3,
52, 57,  7,
57, 50,  1,
13, 19, 63,
19, 15, 67,
15, 12, 61,
72, 48,  0

};

float travesseiro1_normais[] = { 
0.7071, 0.0000, 0.7071,
0.6830, 0.2588, -0.6830,
-0.1830, 0.9659, 0.1830,
-0.6830, -0.2588, 0.6830,
-0.7071, 0.0000, -0.7071,
-0.0491, -0.9620, 0.2688,
0.1646, -0.8319, 0.5300,
0.1729, -0.4431, 0.8796,
-0.3926, -0.3858, 0.8349,
-0.5879, -0.3831, 0.7124,
-0.4605, -0.6605, 0.5930,
-0.3050, -0.6358, 0.7090,
0.0636, 0.1339, 0.9890,
-0.1051, 0.5912, 0.7996,
-0.3679, 0.7207, 0.5876,
-0.6235, 0.1996, 0.7560,
-0.6363, -0.1280, 0.7608,
-0.4468, -0.0998, 0.8891,
-0.4618, 0.1921, 0.8659,
-0.2688, -0.9620, 0.0491,
-0.5930, -0.6606, 0.4605,
-0.7124, -0.3831, 0.5879,
-0.8349, -0.3858, 0.3926,
-0.8796, -0.4431, -0.1729,
-0.5300, -0.8319, -0.1645,
-0.7090, -0.6358, 0.3050,
-0.5876, 0.7207, 0.3679,
-0.7996, 0.5912, 0.1051,
-0.9890, 0.1339, -0.0636,
-0.8891, -0.0998, 0.4468,
-0.7608, -0.1280, 0.6363,
-0.7560, 0.1996, 0.6235,
-0.8659, 0.1921, 0.4618,
0.5876, -0.7207, -0.3679,
0.7559, -0.1996, -0.6235,
0.7608, 0.1280, -0.6363,
0.8891, 0.0998, -0.4468,
0.9890, -0.1339, 0.0636,
0.7996, -0.5912, -0.1051,
0.8659, -0.1921, -0.4618,
0.2688, 0.9620, -0.0491,
0.5300, 0.8319, 0.1645,
0.8796, 0.4431, 0.1729,
0.8349, 0.3858, -0.3926,
0.7124, 0.3831, -0.5879,
0.5930, 0.6605, -0.4605,
0.7090, 0.6358, -0.3050,
0.3679, -0.7207, -0.5876,
0.1051, -0.5912, -0.7996,
-0.0636, -0.1339, -0.9890,
0.4468, 0.0998, -0.8891,
0.6363, 0.1280, -0.7608,
0.6235, -0.1996, -0.7559,
0.4618, -0.1921, -0.8659,
0.0491, 0.9620, -0.2688,
0.4605, 0.6606, -0.5930,
0.5879, 0.3831, -0.7124,
0.3926, 0.3858, -0.8349,
-0.1729, 0.4431, -0.8796,
-0.1645, 0.8319, -0.5300,
0.3050, 0.6358, -0.7090,
-0.1609, -0.9738, 0.1609,
-0.5291, -0.6635, 0.5291,
-0.6527, -0.3846, 0.6527,
0.1239, -0.1620, 0.9790,
-0.4244, -0.2455, 0.8716,
-0.6175, -0.2578, 0.7431,
-0.4836, 0.7296, 0.4836,
-0.6928, 0.2005, 0.6928,
-0.7012, -0.1285, 0.7012,
-0.9790, -0.1620, -0.1239,
-0.8716, -0.2455, 0.4244,
-0.7431, -0.2578, 0.6175,
0.0560, -0.9509, -0.3043,
-0.2400, -0.8037, -0.5445,
-0.5881, -0.3597, -0.7244,
-0.3043, 0.9509, 0.0560,
-0.5445, 0.8037, -0.2400,
-0.7244, 0.3597, -0.5881,
0.6175, 0.2578, -0.7431,
0.4244, 0.2455, -0.8716,
-0.1240, 0.1620, -0.9790,
0.4836, -0.7295, -0.4836,
0.6928, -0.2005, -0.6928,
0.7012, 0.1285, -0.7012,
0.1609, 0.9738, -0.1609,
0.5291, 0.6635, -0.5291,
0.6527, 0.3846, -0.6527,
0.9790, 0.1620, 0.1239,
0.8716, 0.2455, -0.4243,
0.7431, 0.2578, -0.6175,
0.3043, -0.9509, -0.0560,
0.5445, -0.8037, 0.2400,
0.7244, -0.3597, 0.5881,
-0.0560, 0.9509, 0.3043,
0.2400, 0.8037, 0.5445,
0.5881, 0.3598, 0.7244,
0.1830, -0.9659, -0.1830,
-0.0609, -0.9549, 0.2906,
0.1645, -0.8319, 0.5300,
0.1472, -0.4575, 0.8769,
-0.5817, -0.3903, 0.7136,
-0.4605, -0.6606, 0.5930,
0.0343, 0.1383, 0.9898,
-0.3750, 0.7027, 0.6047,
-0.6235, 0.1996, 0.7559,
-0.6329, -0.1200, 0.7649,
-0.2906, -0.9549, 0.0609,
-0.7136, -0.3903, 0.5817,
-0.8769, -0.4576, -0.1472,
-0.6047, 0.7027, 0.3750,
-0.9898, 0.1382, -0.0343,
-0.7649, -0.1200, 0.6329,
-0.7559, 0.1996, 0.6235,
0.6047, -0.7027, -0.3750,
0.7649, 0.1200, -0.6329,
0.8891, 0.0999, -0.4468,
0.9898, -0.1383, 0.0343,
0.2906, 0.9549, -0.0609,
0.8769, 0.4576, 0.1472,
0.7136, 0.3903, -0.5817,
0.5930, 0.6606, -0.4605,
0.3750, -0.7027, -0.6046,
-0.0343, -0.1383, -0.9898,
0.6329, 0.1200, -0.7649,
0.0609, 0.9549, -0.2906,
0.5817, 0.3903, -0.7136,
-0.1472, 0.4575, -0.8769,
0.1240, -0.1620, 0.9790,
-0.6927, 0.2005, 0.6927,
0.4243, 0.2455, -0.8716,
-0.1239, 0.1620, -0.9790,
0.4836, -0.7296, -0.4836,
0.6928, -0.2005, -0.6927,
0.8716, 0.2455, -0.4244,
0.5881, 0.3597, 0.7244,

};
