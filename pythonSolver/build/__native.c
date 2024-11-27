#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"create_corner_database", (PyCFunction)CPyPy_create_corner_database, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "pattern_database",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_pattern_database(void)
{
    PyObject* modname = NULL;
    if (CPyModule_pattern_database_internal) {
        Py_INCREF(CPyModule_pattern_database_internal);
        return CPyModule_pattern_database_internal;
    }
    CPyModule_pattern_database_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_pattern_database_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_pattern_database_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_pattern_database_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_pattern_database_internal;
    fail:
    Py_CLEAR(CPyModule_pattern_database_internal);
    Py_CLEAR(modname);
    return NULL;
}

PyObject *CPyDef_create_corner_database(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_i;
    char cpy_r_r10;
    int32_t cpy_r_r11;
    char cpy_r_r12;
    CPyTagged cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_corners;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_corner_orientations;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_corner_permutation;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_a;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_b;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_c;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_d;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_e;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_f;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_g;
    PyObject *cpy_r_r56;
    PyObject **cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject **cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    CPyPtr cpy_r_r67;
    CPyPtr cpy_r_r68;
    CPyPtr cpy_r_r69;
    CPyPtr cpy_r_r70;
    CPyPtr cpy_r_r71;
    CPyPtr cpy_r_r72;
    CPyPtr cpy_r_r73;
    CPyPtr cpy_r_r74;
    CPyPtr cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject **cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject **cpy_r_r82;
    PyObject *cpy_r_r83;
    char cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject **cpy_r_r87;
    PyObject *cpy_r_r88;
    char cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject **cpy_r_r102;
    PyObject *cpy_r_r103;
    char cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject **cpy_r_r107;
    PyObject *cpy_r_r108;
    char cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject **cpy_r_r112;
    PyObject *cpy_r_r113;
    char cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject **cpy_r_r117;
    PyObject *cpy_r_r118;
    char cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    CPyPtr cpy_r_r124;
    CPyPtr cpy_r_r125;
    CPyPtr cpy_r_r126;
    CPyPtr cpy_r_r127;
    CPyTagged cpy_r_r128;
    CPyPtr cpy_r_r129;
    int64_t cpy_r_r130;
    CPyTagged cpy_r_r131;
    char cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    CPyPtr cpy_r_r138;
    CPyPtr cpy_r_r139;
    CPyPtr cpy_r_r140;
    CPyPtr cpy_r_r141;
    CPyTagged cpy_r_r142;
    CPyPtr cpy_r_r143;
    int64_t cpy_r_r144;
    CPyTagged cpy_r_r145;
    char cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    CPyPtr cpy_r_r152;
    CPyPtr cpy_r_r153;
    CPyPtr cpy_r_r154;
    CPyPtr cpy_r_r155;
    CPyTagged cpy_r_r156;
    CPyPtr cpy_r_r157;
    int64_t cpy_r_r158;
    CPyTagged cpy_r_r159;
    char cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    CPyPtr cpy_r_r166;
    CPyPtr cpy_r_r167;
    CPyPtr cpy_r_r168;
    CPyPtr cpy_r_r169;
    CPyTagged cpy_r_r170;
    CPyPtr cpy_r_r171;
    int64_t cpy_r_r172;
    CPyTagged cpy_r_r173;
    char cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    CPyPtr cpy_r_r180;
    CPyPtr cpy_r_r181;
    CPyPtr cpy_r_r182;
    CPyPtr cpy_r_r183;
    CPyTagged cpy_r_r184;
    CPyPtr cpy_r_r185;
    int64_t cpy_r_r186;
    CPyTagged cpy_r_r187;
    char cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    CPyPtr cpy_r_r194;
    CPyPtr cpy_r_r195;
    CPyPtr cpy_r_r196;
    CPyPtr cpy_r_r197;
    CPyTagged cpy_r_r198;
    CPyPtr cpy_r_r199;
    int64_t cpy_r_r200;
    CPyTagged cpy_r_r201;
    char cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    CPyPtr cpy_r_r208;
    CPyPtr cpy_r_r209;
    CPyPtr cpy_r_r210;
    CPyPtr cpy_r_r211;
    CPyTagged cpy_r_r212;
    CPyPtr cpy_r_r213;
    int64_t cpy_r_r214;
    CPyTagged cpy_r_r215;
    char cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    CPyPtr cpy_r_r219;
    CPyPtr cpy_r_r220;
    CPyPtr cpy_r_r221;
    CPyPtr cpy_r_r222;
    CPyPtr cpy_r_r223;
    CPyPtr cpy_r_r224;
    CPyPtr cpy_r_r225;
    CPyPtr cpy_r_r226;
    PyObject *cpy_r_c_orientation;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject **cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject **cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject **cpy_r_r245;
    PyObject *cpy_r_r246;
    CPyTagged cpy_r_r247;
    CPyTagged cpy_r_r248;
    CPyTagged cpy_r_r249;
    CPyTagged cpy_r_r250;
    CPyTagged cpy_r_r251;
    CPyTagged cpy_r_r252;
    CPyTagged cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject **cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject **cpy_r_r268;
    PyObject *cpy_r_r269;
    CPyTagged cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_k;
    char cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject **cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    int32_t cpy_r_r283;
    char cpy_r_r284;
    CPyTagged cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject **cpy_r_r291;
    PyObject *cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_depth_limit;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject **cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject **cpy_r_r306;
    PyObject *cpy_r_r307;
    int32_t cpy_r_r308;
    char cpy_r_r309;
    char cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    PyObject **cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    char cpy_r_r320;
    char cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'Cube' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 6, CPyStatic_globals);
        goto CPyL131;
    }
    cpy_r_r3 = CPyStatics[4]; /* 'create_solved_cube' */
    PyObject *cpy_r_r4[1] = {cpy_r_r2};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 6, CPyStatic_globals);
        goto CPyL132;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r7 = PyList_New(0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 7, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r8 = 0;
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r8);
    cpy_r_i = cpy_r_r9;
CPyL4: ;
    cpy_r_r10 = (Py_ssize_t)cpy_r_r8 < (Py_ssize_t)16;
    if (!cpy_r_r10) goto CPyL134;
    cpy_r_r11 = PyList_Append(cpy_r_r7, cpy_r_i);
    CPy_DECREF(cpy_r_i);
    cpy_r_r12 = cpy_r_r11 >= 0;
    if (unlikely(!cpy_r_r12)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 7, CPyStatic_globals);
        goto CPyL135;
    }
    cpy_r_r13 = cpy_r_r8 + 2;
    cpy_r_r8 = cpy_r_r13;
    cpy_r_r14 = CPyTagged_StealAsObject(cpy_r_r13);
    cpy_r_i = cpy_r_r14;
    goto CPyL4;
CPyL7: ;
    cpy_r_corners = cpy_r_r7;
    cpy_r_r15 = CPyStatics[19]; /* 0 */
    CPy_INCREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r16 = PyList_New(0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 9, CPyStatic_globals);
        goto CPyL136;
    }
    cpy_r_corner_orientations = cpy_r_r16;
    cpy_r_r17 = PyList_New(0);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 10, CPyStatic_globals);
        goto CPyL137;
    }
    cpy_r_corner_permutation = cpy_r_r17;
    cpy_r_r18 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 11, CPyStatic_globals);
        goto CPyL138;
    }
CPyL10: ;
    cpy_r_r19 = PyIter_Next(cpy_r_r18);
    if (cpy_r_r19 == NULL) goto CPyL139;
    cpy_r_a = cpy_r_r19;
    cpy_r_r20 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r21[2] = {cpy_r_corners, cpy_r_a};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_VectorcallMethod(cpy_r_r20, cpy_r_r22, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 12, CPyStatic_globals);
        goto CPyL140;
    } else
        goto CPyL141;
CPyL12: ;
    cpy_r_r24 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 13, CPyStatic_globals);
        goto CPyL140;
    }
CPyL13: ;
    cpy_r_r25 = PyIter_Next(cpy_r_r24);
    if (cpy_r_r25 == NULL) goto CPyL142;
    cpy_r_b = cpy_r_r25;
    cpy_r_r26 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r27[2] = {cpy_r_corners, cpy_r_b};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = PyObject_VectorcallMethod(cpy_r_r26, cpy_r_r28, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 14, CPyStatic_globals);
        goto CPyL143;
    } else
        goto CPyL144;
CPyL15: ;
    cpy_r_r30 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 15, CPyStatic_globals);
        goto CPyL143;
    }
CPyL16: ;
    cpy_r_r31 = PyIter_Next(cpy_r_r30);
    if (cpy_r_r31 == NULL) goto CPyL145;
    cpy_r_c = cpy_r_r31;
    cpy_r_r32 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r33[2] = {cpy_r_corners, cpy_r_c};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r34, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 16, CPyStatic_globals);
        goto CPyL146;
    } else
        goto CPyL147;
CPyL18: ;
    cpy_r_r36 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 17, CPyStatic_globals);
        goto CPyL146;
    }
CPyL19: ;
    cpy_r_r37 = PyIter_Next(cpy_r_r36);
    if (cpy_r_r37 == NULL) goto CPyL148;
    cpy_r_d = cpy_r_r37;
    cpy_r_r38 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r39[2] = {cpy_r_corners, cpy_r_d};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_VectorcallMethod(cpy_r_r38, cpy_r_r40, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 18, CPyStatic_globals);
        goto CPyL149;
    } else
        goto CPyL150;
CPyL21: ;
    cpy_r_r42 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 19, CPyStatic_globals);
        goto CPyL149;
    }
CPyL22: ;
    cpy_r_r43 = PyIter_Next(cpy_r_r42);
    if (cpy_r_r43 == NULL) goto CPyL151;
    cpy_r_e = cpy_r_r43;
    cpy_r_r44 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r45[2] = {cpy_r_corners, cpy_r_e};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 20, CPyStatic_globals);
        goto CPyL152;
    } else
        goto CPyL153;
CPyL24: ;
    cpy_r_r48 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 21, CPyStatic_globals);
        goto CPyL152;
    }
CPyL25: ;
    cpy_r_r49 = PyIter_Next(cpy_r_r48);
    if (cpy_r_r49 == NULL) goto CPyL154;
    cpy_r_f = cpy_r_r49;
    cpy_r_r50 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r51[2] = {cpy_r_corners, cpy_r_f};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = PyObject_VectorcallMethod(cpy_r_r50, cpy_r_r52, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 22, CPyStatic_globals);
        goto CPyL155;
    } else
        goto CPyL156;
CPyL27: ;
    cpy_r_r54 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 23, CPyStatic_globals);
        goto CPyL155;
    }
CPyL28: ;
    cpy_r_r55 = PyIter_Next(cpy_r_r54);
    if (cpy_r_r55 == NULL) goto CPyL157;
    cpy_r_g = cpy_r_r55;
    cpy_r_r56 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r57[2] = {cpy_r_corners, cpy_r_g};
    cpy_r_r58 = (PyObject **)&cpy_r_r57;
    cpy_r_r59 = PyObject_VectorcallMethod(cpy_r_r56, cpy_r_r58, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 24, CPyStatic_globals);
        goto CPyL158;
    } else
        goto CPyL159;
CPyL30: ;
    cpy_r_r60 = PyObject_GetIter(cpy_r_corners);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 25, CPyStatic_globals);
        goto CPyL158;
    }
CPyL31: ;
    cpy_r_r61 = PyIter_Next(cpy_r_r60);
    if (cpy_r_r61 == NULL) goto CPyL160;
    cpy_r_r62 = CPyStatics[5]; /* 'remove' */
    PyObject *cpy_r_r63[2] = {cpy_r_corners, cpy_r_r61};
    cpy_r_r64 = (PyObject **)&cpy_r_r63;
    cpy_r_r65 = PyObject_VectorcallMethod(cpy_r_r62, cpy_r_r64, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 26, CPyStatic_globals);
        goto CPyL161;
    } else
        goto CPyL162;
CPyL33: ;
    cpy_r_r66 = PyList_New(8);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 27, CPyStatic_globals);
        goto CPyL161;
    }
    cpy_r_r67 = (CPyPtr)&((PyListObject *)cpy_r_r66)->ob_item;
    cpy_r_r68 = *(CPyPtr *)cpy_r_r67;
    CPy_INCREF(cpy_r_a);
    *(PyObject * *)cpy_r_r68 = cpy_r_a;
    CPy_INCREF(cpy_r_b);
    cpy_r_r69 = cpy_r_r68 + 8;
    *(PyObject * *)cpy_r_r69 = cpy_r_b;
    CPy_INCREF(cpy_r_c);
    cpy_r_r70 = cpy_r_r68 + 16;
    *(PyObject * *)cpy_r_r70 = cpy_r_c;
    CPy_INCREF(cpy_r_d);
    cpy_r_r71 = cpy_r_r68 + 24;
    *(PyObject * *)cpy_r_r71 = cpy_r_d;
    CPy_INCREF(cpy_r_e);
    cpy_r_r72 = cpy_r_r68 + 32;
    *(PyObject * *)cpy_r_r72 = cpy_r_e;
    CPy_INCREF(cpy_r_f);
    cpy_r_r73 = cpy_r_r68 + 40;
    *(PyObject * *)cpy_r_r73 = cpy_r_f;
    CPy_INCREF(cpy_r_g);
    cpy_r_r74 = cpy_r_r68 + 48;
    *(PyObject * *)cpy_r_r74 = cpy_r_g;
    CPy_INCREF(cpy_r_r61);
    cpy_r_r75 = cpy_r_r68 + 56;
    *(PyObject * *)cpy_r_r75 = cpy_r_r61;
    cpy_r_r76 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r77[2] = {cpy_r_corner_permutation, cpy_r_r66};
    cpy_r_r78 = (PyObject **)&cpy_r_r77;
    cpy_r_r79 = PyObject_VectorcallMethod(cpy_r_r76, cpy_r_r78, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 27, CPyStatic_globals);
        goto CPyL163;
    } else
        goto CPyL164;
CPyL35: ;
    CPy_DECREF(cpy_r_r66);
    cpy_r_r80 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r81[2] = {cpy_r_corners, cpy_r_r61};
    cpy_r_r82 = (PyObject **)&cpy_r_r81;
    cpy_r_r83 = PyObject_VectorcallMethod(cpy_r_r80, cpy_r_r82, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 28, CPyStatic_globals);
        goto CPyL161;
    } else
        goto CPyL165;
CPyL36: ;
    CPy_DECREF(cpy_r_r61);
    goto CPyL31;
CPyL37: ;
    cpy_r_r84 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r84)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 25, CPyStatic_globals);
        goto CPyL158;
    }
    cpy_r_r85 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r86[2] = {cpy_r_corners, cpy_r_g};
    cpy_r_r87 = (PyObject **)&cpy_r_r86;
    cpy_r_r88 = PyObject_VectorcallMethod(cpy_r_r85, cpy_r_r87, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 29, CPyStatic_globals);
        goto CPyL158;
    } else
        goto CPyL166;
CPyL39: ;
    CPy_DECREF(cpy_r_g);
    goto CPyL28;
CPyL40: ;
    cpy_r_r89 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 23, CPyStatic_globals);
        goto CPyL155;
    }
    cpy_r_r90 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r91[2] = {cpy_r_corners, cpy_r_f};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = PyObject_VectorcallMethod(cpy_r_r90, cpy_r_r92, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 30, CPyStatic_globals);
        goto CPyL155;
    } else
        goto CPyL167;
CPyL42: ;
    CPy_DECREF(cpy_r_f);
    goto CPyL25;
CPyL43: ;
    cpy_r_r94 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 21, CPyStatic_globals);
        goto CPyL152;
    }
    cpy_r_r95 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r96[2] = {cpy_r_corners, cpy_r_e};
    cpy_r_r97 = (PyObject **)&cpy_r_r96;
    cpy_r_r98 = PyObject_VectorcallMethod(cpy_r_r95, cpy_r_r97, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 31, CPyStatic_globals);
        goto CPyL152;
    } else
        goto CPyL168;
CPyL45: ;
    CPy_DECREF(cpy_r_e);
    goto CPyL22;
CPyL46: ;
    cpy_r_r99 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 19, CPyStatic_globals);
        goto CPyL149;
    }
    cpy_r_r100 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r101[2] = {cpy_r_corners, cpy_r_d};
    cpy_r_r102 = (PyObject **)&cpy_r_r101;
    cpy_r_r103 = PyObject_VectorcallMethod(cpy_r_r100, cpy_r_r102, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 32, CPyStatic_globals);
        goto CPyL149;
    } else
        goto CPyL169;
CPyL48: ;
    CPy_DECREF(cpy_r_d);
    goto CPyL19;
CPyL49: ;
    cpy_r_r104 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r104)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 17, CPyStatic_globals);
        goto CPyL146;
    }
    cpy_r_r105 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r106[2] = {cpy_r_corners, cpy_r_c};
    cpy_r_r107 = (PyObject **)&cpy_r_r106;
    cpy_r_r108 = PyObject_VectorcallMethod(cpy_r_r105, cpy_r_r107, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 33, CPyStatic_globals);
        goto CPyL146;
    } else
        goto CPyL170;
CPyL51: ;
    CPy_DECREF(cpy_r_c);
    goto CPyL16;
CPyL52: ;
    cpy_r_r109 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r109)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 15, CPyStatic_globals);
        goto CPyL143;
    }
    cpy_r_r110 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r111[2] = {cpy_r_corners, cpy_r_b};
    cpy_r_r112 = (PyObject **)&cpy_r_r111;
    cpy_r_r113 = PyObject_VectorcallMethod(cpy_r_r110, cpy_r_r112, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 34, CPyStatic_globals);
        goto CPyL143;
    } else
        goto CPyL171;
CPyL54: ;
    CPy_DECREF(cpy_r_b);
    goto CPyL13;
CPyL55: ;
    cpy_r_r114 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r114)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 13, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r115 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r116[2] = {cpy_r_corners, cpy_r_a};
    cpy_r_r117 = (PyObject **)&cpy_r_r116;
    cpy_r_r118 = PyObject_VectorcallMethod(cpy_r_r115, cpy_r_r117, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 35, CPyStatic_globals);
        goto CPyL140;
    } else
        goto CPyL172;
CPyL57: ;
    CPy_DECREF(cpy_r_a);
    goto CPyL10;
CPyL58: ;
    cpy_r_r119 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r119)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 11, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r120 = PyList_New(3);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 37, CPyStatic_globals);
        goto CPyL173;
    }
    cpy_r_r121 = CPyStatics[19]; /* 0 */
    cpy_r_r122 = CPyStatics[20]; /* 1 */
    cpy_r_r123 = CPyStatics[21]; /* 2 */
    cpy_r_r124 = (CPyPtr)&((PyListObject *)cpy_r_r120)->ob_item;
    cpy_r_r125 = *(CPyPtr *)cpy_r_r124;
    CPy_INCREF(cpy_r_r121);
    *(PyObject * *)cpy_r_r125 = cpy_r_r121;
    CPy_INCREF(cpy_r_r122);
    cpy_r_r126 = cpy_r_r125 + 8;
    *(PyObject * *)cpy_r_r126 = cpy_r_r122;
    CPy_INCREF(cpy_r_r123);
    cpy_r_r127 = cpy_r_r125 + 16;
    *(PyObject * *)cpy_r_r127 = cpy_r_r123;
    cpy_r_r128 = 0;
CPyL61: ;
    cpy_r_r129 = (CPyPtr)&((PyVarObject *)cpy_r_r120)->ob_size;
    cpy_r_r130 = *(int64_t *)cpy_r_r129;
    cpy_r_r131 = cpy_r_r130 << 1;
    cpy_r_r132 = (Py_ssize_t)cpy_r_r128 < (Py_ssize_t)cpy_r_r131;
    if (!cpy_r_r132) goto CPyL174;
    cpy_r_r133 = CPyList_GetItemUnsafe(cpy_r_r120, cpy_r_r128);
    cpy_r_a = cpy_r_r133;
    cpy_r_r134 = PyList_New(3);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 38, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r135 = CPyStatics[19]; /* 0 */
    cpy_r_r136 = CPyStatics[20]; /* 1 */
    cpy_r_r137 = CPyStatics[21]; /* 2 */
    cpy_r_r138 = (CPyPtr)&((PyListObject *)cpy_r_r134)->ob_item;
    cpy_r_r139 = *(CPyPtr *)cpy_r_r138;
    CPy_INCREF(cpy_r_r135);
    *(PyObject * *)cpy_r_r139 = cpy_r_r135;
    CPy_INCREF(cpy_r_r136);
    cpy_r_r140 = cpy_r_r139 + 8;
    *(PyObject * *)cpy_r_r140 = cpy_r_r136;
    CPy_INCREF(cpy_r_r137);
    cpy_r_r141 = cpy_r_r139 + 16;
    *(PyObject * *)cpy_r_r141 = cpy_r_r137;
    cpy_r_r142 = 0;
CPyL64: ;
    cpy_r_r143 = (CPyPtr)&((PyVarObject *)cpy_r_r134)->ob_size;
    cpy_r_r144 = *(int64_t *)cpy_r_r143;
    cpy_r_r145 = cpy_r_r144 << 1;
    cpy_r_r146 = (Py_ssize_t)cpy_r_r142 < (Py_ssize_t)cpy_r_r145;
    if (!cpy_r_r146) goto CPyL176;
    cpy_r_r147 = CPyList_GetItemUnsafe(cpy_r_r134, cpy_r_r142);
    cpy_r_b = cpy_r_r147;
    cpy_r_r148 = PyList_New(3);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 39, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r149 = CPyStatics[19]; /* 0 */
    cpy_r_r150 = CPyStatics[20]; /* 1 */
    cpy_r_r151 = CPyStatics[21]; /* 2 */
    cpy_r_r152 = (CPyPtr)&((PyListObject *)cpy_r_r148)->ob_item;
    cpy_r_r153 = *(CPyPtr *)cpy_r_r152;
    CPy_INCREF(cpy_r_r149);
    *(PyObject * *)cpy_r_r153 = cpy_r_r149;
    CPy_INCREF(cpy_r_r150);
    cpy_r_r154 = cpy_r_r153 + 8;
    *(PyObject * *)cpy_r_r154 = cpy_r_r150;
    CPy_INCREF(cpy_r_r151);
    cpy_r_r155 = cpy_r_r153 + 16;
    *(PyObject * *)cpy_r_r155 = cpy_r_r151;
    cpy_r_r156 = 0;
CPyL67: ;
    cpy_r_r157 = (CPyPtr)&((PyVarObject *)cpy_r_r148)->ob_size;
    cpy_r_r158 = *(int64_t *)cpy_r_r157;
    cpy_r_r159 = cpy_r_r158 << 1;
    cpy_r_r160 = (Py_ssize_t)cpy_r_r156 < (Py_ssize_t)cpy_r_r159;
    if (!cpy_r_r160) goto CPyL178;
    cpy_r_r161 = CPyList_GetItemUnsafe(cpy_r_r148, cpy_r_r156);
    cpy_r_c = cpy_r_r161;
    cpy_r_r162 = PyList_New(3);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 40, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r163 = CPyStatics[19]; /* 0 */
    cpy_r_r164 = CPyStatics[20]; /* 1 */
    cpy_r_r165 = CPyStatics[21]; /* 2 */
    cpy_r_r166 = (CPyPtr)&((PyListObject *)cpy_r_r162)->ob_item;
    cpy_r_r167 = *(CPyPtr *)cpy_r_r166;
    CPy_INCREF(cpy_r_r163);
    *(PyObject * *)cpy_r_r167 = cpy_r_r163;
    CPy_INCREF(cpy_r_r164);
    cpy_r_r168 = cpy_r_r167 + 8;
    *(PyObject * *)cpy_r_r168 = cpy_r_r164;
    CPy_INCREF(cpy_r_r165);
    cpy_r_r169 = cpy_r_r167 + 16;
    *(PyObject * *)cpy_r_r169 = cpy_r_r165;
    cpy_r_r170 = 0;
CPyL70: ;
    cpy_r_r171 = (CPyPtr)&((PyVarObject *)cpy_r_r162)->ob_size;
    cpy_r_r172 = *(int64_t *)cpy_r_r171;
    cpy_r_r173 = cpy_r_r172 << 1;
    cpy_r_r174 = (Py_ssize_t)cpy_r_r170 < (Py_ssize_t)cpy_r_r173;
    if (!cpy_r_r174) goto CPyL180;
    cpy_r_r175 = CPyList_GetItemUnsafe(cpy_r_r162, cpy_r_r170);
    cpy_r_d = cpy_r_r175;
    cpy_r_r176 = PyList_New(3);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 41, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r177 = CPyStatics[19]; /* 0 */
    cpy_r_r178 = CPyStatics[20]; /* 1 */
    cpy_r_r179 = CPyStatics[21]; /* 2 */
    cpy_r_r180 = (CPyPtr)&((PyListObject *)cpy_r_r176)->ob_item;
    cpy_r_r181 = *(CPyPtr *)cpy_r_r180;
    CPy_INCREF(cpy_r_r177);
    *(PyObject * *)cpy_r_r181 = cpy_r_r177;
    CPy_INCREF(cpy_r_r178);
    cpy_r_r182 = cpy_r_r181 + 8;
    *(PyObject * *)cpy_r_r182 = cpy_r_r178;
    CPy_INCREF(cpy_r_r179);
    cpy_r_r183 = cpy_r_r181 + 16;
    *(PyObject * *)cpy_r_r183 = cpy_r_r179;
    cpy_r_r184 = 0;
CPyL73: ;
    cpy_r_r185 = (CPyPtr)&((PyVarObject *)cpy_r_r176)->ob_size;
    cpy_r_r186 = *(int64_t *)cpy_r_r185;
    cpy_r_r187 = cpy_r_r186 << 1;
    cpy_r_r188 = (Py_ssize_t)cpy_r_r184 < (Py_ssize_t)cpy_r_r187;
    if (!cpy_r_r188) goto CPyL182;
    cpy_r_r189 = CPyList_GetItemUnsafe(cpy_r_r176, cpy_r_r184);
    cpy_r_e = cpy_r_r189;
    cpy_r_r190 = PyList_New(3);
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 42, CPyStatic_globals);
        goto CPyL183;
    }
    cpy_r_r191 = CPyStatics[19]; /* 0 */
    cpy_r_r192 = CPyStatics[20]; /* 1 */
    cpy_r_r193 = CPyStatics[21]; /* 2 */
    cpy_r_r194 = (CPyPtr)&((PyListObject *)cpy_r_r190)->ob_item;
    cpy_r_r195 = *(CPyPtr *)cpy_r_r194;
    CPy_INCREF(cpy_r_r191);
    *(PyObject * *)cpy_r_r195 = cpy_r_r191;
    CPy_INCREF(cpy_r_r192);
    cpy_r_r196 = cpy_r_r195 + 8;
    *(PyObject * *)cpy_r_r196 = cpy_r_r192;
    CPy_INCREF(cpy_r_r193);
    cpy_r_r197 = cpy_r_r195 + 16;
    *(PyObject * *)cpy_r_r197 = cpy_r_r193;
    cpy_r_r198 = 0;
CPyL76: ;
    cpy_r_r199 = (CPyPtr)&((PyVarObject *)cpy_r_r190)->ob_size;
    cpy_r_r200 = *(int64_t *)cpy_r_r199;
    cpy_r_r201 = cpy_r_r200 << 1;
    cpy_r_r202 = (Py_ssize_t)cpy_r_r198 < (Py_ssize_t)cpy_r_r201;
    if (!cpy_r_r202) goto CPyL184;
    cpy_r_r203 = CPyList_GetItemUnsafe(cpy_r_r190, cpy_r_r198);
    cpy_r_f = cpy_r_r203;
    cpy_r_r204 = PyList_New(3);
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 43, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r205 = CPyStatics[19]; /* 0 */
    cpy_r_r206 = CPyStatics[20]; /* 1 */
    cpy_r_r207 = CPyStatics[21]; /* 2 */
    cpy_r_r208 = (CPyPtr)&((PyListObject *)cpy_r_r204)->ob_item;
    cpy_r_r209 = *(CPyPtr *)cpy_r_r208;
    CPy_INCREF(cpy_r_r205);
    *(PyObject * *)cpy_r_r209 = cpy_r_r205;
    CPy_INCREF(cpy_r_r206);
    cpy_r_r210 = cpy_r_r209 + 8;
    *(PyObject * *)cpy_r_r210 = cpy_r_r206;
    CPy_INCREF(cpy_r_r207);
    cpy_r_r211 = cpy_r_r209 + 16;
    *(PyObject * *)cpy_r_r211 = cpy_r_r207;
    cpy_r_r212 = 0;
CPyL79: ;
    cpy_r_r213 = (CPyPtr)&((PyVarObject *)cpy_r_r204)->ob_size;
    cpy_r_r214 = *(int64_t *)cpy_r_r213;
    cpy_r_r215 = cpy_r_r214 << 1;
    cpy_r_r216 = (Py_ssize_t)cpy_r_r212 < (Py_ssize_t)cpy_r_r215;
    if (!cpy_r_r216) goto CPyL186;
    cpy_r_r217 = CPyList_GetItemUnsafe(cpy_r_r204, cpy_r_r212);
    cpy_r_g = cpy_r_r217;
    cpy_r_r218 = PyList_New(7);
    if (unlikely(cpy_r_r218 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 44, CPyStatic_globals);
        goto CPyL187;
    }
    cpy_r_r219 = (CPyPtr)&((PyListObject *)cpy_r_r218)->ob_item;
    cpy_r_r220 = *(CPyPtr *)cpy_r_r219;
    CPy_INCREF(cpy_r_a);
    *(PyObject * *)cpy_r_r220 = cpy_r_a;
    CPy_INCREF(cpy_r_b);
    cpy_r_r221 = cpy_r_r220 + 8;
    *(PyObject * *)cpy_r_r221 = cpy_r_b;
    CPy_INCREF(cpy_r_c);
    cpy_r_r222 = cpy_r_r220 + 16;
    *(PyObject * *)cpy_r_r222 = cpy_r_c;
    CPy_INCREF(cpy_r_d);
    cpy_r_r223 = cpy_r_r220 + 24;
    *(PyObject * *)cpy_r_r223 = cpy_r_d;
    CPy_INCREF(cpy_r_e);
    cpy_r_r224 = cpy_r_r220 + 32;
    *(PyObject * *)cpy_r_r224 = cpy_r_e;
    CPy_INCREF(cpy_r_f);
    cpy_r_r225 = cpy_r_r220 + 40;
    *(PyObject * *)cpy_r_r225 = cpy_r_f;
    cpy_r_r226 = cpy_r_r220 + 48;
    *(PyObject * *)cpy_r_r226 = cpy_r_g;
    cpy_r_c_orientation = cpy_r_r218;
    cpy_r_r227 = CPyModule_builtins;
    cpy_r_r228 = CPyStatics[7]; /* 'sum' */
    cpy_r_r229 = CPyObject_GetAttr(cpy_r_r227, cpy_r_r228);
    if (unlikely(cpy_r_r229 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 45, CPyStatic_globals);
        goto CPyL188;
    }
    PyObject *cpy_r_r230[1] = {cpy_r_c_orientation};
    cpy_r_r231 = (PyObject **)&cpy_r_r230;
    cpy_r_r232 = _PyObject_Vectorcall(cpy_r_r229, cpy_r_r231, 1, 0);
    CPy_DECREF(cpy_r_r229);
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 45, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r233 = CPyStatics[22]; /* 3 */
    cpy_r_r234 = PyNumber_Remainder(cpy_r_r232, cpy_r_r233);
    CPy_DECREF(cpy_r_r232);
    if (unlikely(cpy_r_r234 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 45, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r235 = CPyStatics[22]; /* 3 */
    cpy_r_r236 = PyNumber_Subtract(cpy_r_r235, cpy_r_r234);
    CPy_DECREF(cpy_r_r234);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 45, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r237 = CPyStatics[22]; /* 3 */
    cpy_r_r238 = PyNumber_Remainder(cpy_r_r236, cpy_r_r237);
    CPy_DECREF(cpy_r_r236);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 45, CPyStatic_globals);
        goto CPyL188;
    }
    cpy_r_r239 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r240[2] = {cpy_r_c_orientation, cpy_r_r238};
    cpy_r_r241 = (PyObject **)&cpy_r_r240;
    cpy_r_r242 = PyObject_VectorcallMethod(cpy_r_r239, cpy_r_r241, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 46, CPyStatic_globals);
        goto CPyL189;
    } else
        goto CPyL190;
CPyL87: ;
    CPy_DECREF(cpy_r_r238);
    cpy_r_r243 = CPyStatics[6]; /* 'append' */
    PyObject *cpy_r_r244[2] = {cpy_r_corner_orientations, cpy_r_c_orientation};
    cpy_r_r245 = (PyObject **)&cpy_r_r244;
    cpy_r_r246 = PyObject_VectorcallMethod(cpy_r_r243, cpy_r_r245, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 47, CPyStatic_globals);
        goto CPyL188;
    } else
        goto CPyL191;
CPyL88: ;
    CPy_DECREF(cpy_r_c_orientation);
    cpy_r_r247 = cpy_r_r212 + 2;
    cpy_r_r212 = cpy_r_r247;
    goto CPyL79;
CPyL90: ;
    cpy_r_r248 = cpy_r_r198 + 2;
    cpy_r_r198 = cpy_r_r248;
    goto CPyL76;
CPyL91: ;
    cpy_r_r249 = cpy_r_r184 + 2;
    cpy_r_r184 = cpy_r_r249;
    goto CPyL73;
CPyL92: ;
    cpy_r_r250 = cpy_r_r170 + 2;
    cpy_r_r170 = cpy_r_r250;
    goto CPyL70;
CPyL93: ;
    cpy_r_r251 = cpy_r_r156 + 2;
    cpy_r_r156 = cpy_r_r251;
    goto CPyL67;
CPyL94: ;
    cpy_r_r252 = cpy_r_r142 + 2;
    cpy_r_r142 = cpy_r_r252;
    goto CPyL64;
CPyL95: ;
    cpy_r_r253 = cpy_r_r128 + 2;
    cpy_r_r128 = cpy_r_r253;
    goto CPyL61;
CPyL96: ;
    cpy_r_r254 = PyObject_GetIter(cpy_r_corner_permutation);
    CPy_DECREF(cpy_r_corner_permutation);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 50, CPyStatic_globals);
        goto CPyL192;
    }
CPyL97: ;
    cpy_r_r255 = PyIter_Next(cpy_r_r254);
    if (cpy_r_r255 == NULL) goto CPyL193;
    cpy_r_r256 = PyObject_GetIter(cpy_r_corner_orientations);
    if (unlikely(cpy_r_r256 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 51, CPyStatic_globals);
        goto CPyL194;
    }
CPyL99: ;
    cpy_r_r257 = PyIter_Next(cpy_r_r256);
    if (cpy_r_r257 == NULL) goto CPyL195;
    cpy_r_r258 = CPyModule_builtins;
    cpy_r_r259 = CPyStatics[8]; /* 'print' */
    cpy_r_r260 = CPyObject_GetAttr(cpy_r_r258, cpy_r_r259);
    if (unlikely(cpy_r_r260 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 52, CPyStatic_globals);
        goto CPyL196;
    }
    PyObject *cpy_r_r261[1] = {cpy_r_r255};
    cpy_r_r262 = (PyObject **)&cpy_r_r261;
    cpy_r_r263 = _PyObject_Vectorcall(cpy_r_r260, cpy_r_r262, 1, 0);
    CPy_DECREF(cpy_r_r260);
    if (unlikely(cpy_r_r263 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 52, CPyStatic_globals);
        goto CPyL196;
    } else
        goto CPyL197;
CPyL102: ;
    cpy_r_r264 = CPyModule_builtins;
    cpy_r_r265 = CPyStatics[8]; /* 'print' */
    cpy_r_r266 = CPyObject_GetAttr(cpy_r_r264, cpy_r_r265);
    if (unlikely(cpy_r_r266 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 53, CPyStatic_globals);
        goto CPyL196;
    }
    PyObject *cpy_r_r267[1] = {cpy_r_r257};
    cpy_r_r268 = (PyObject **)&cpy_r_r267;
    cpy_r_r269 = _PyObject_Vectorcall(cpy_r_r266, cpy_r_r268, 1, 0);
    CPy_DECREF(cpy_r_r266);
    if (unlikely(cpy_r_r269 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 53, CPyStatic_globals);
        goto CPyL196;
    } else
        goto CPyL198;
CPyL104: ;
    cpy_r_r270 = 0;
    cpy_r_r271 = CPyTagged_StealAsObject(cpy_r_r270);
    cpy_r_k = cpy_r_r271;
CPyL105: ;
    cpy_r_r272 = (Py_ssize_t)cpy_r_r270 < (Py_ssize_t)16;
    if (!cpy_r_r272) goto CPyL199;
    cpy_r_r273 = PyObject_GetItem(cpy_r_r255, cpy_r_k);
    if (unlikely(cpy_r_r273 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 56, CPyStatic_globals);
        goto CPyL200;
    }
    cpy_r_r274 = PyObject_GetItem(cpy_r_r257, cpy_r_k);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 56, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r275 = CPyStatic_globals;
    cpy_r_r276 = CPyStatics[9]; /* 'cubie' */
    cpy_r_r277 = CPyDict_GetItem(cpy_r_r275, cpy_r_r276);
    if (unlikely(cpy_r_r277 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 56, CPyStatic_globals);
        goto CPyL202;
    }
    PyObject *cpy_r_r278[2] = {cpy_r_r273, cpy_r_r274};
    cpy_r_r279 = (PyObject **)&cpy_r_r278;
    cpy_r_r280 = _PyObject_Vectorcall(cpy_r_r277, cpy_r_r279, 2, 0);
    CPy_DECREF(cpy_r_r277);
    if (unlikely(cpy_r_r280 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 56, CPyStatic_globals);
        goto CPyL202;
    }
    CPy_DECREF(cpy_r_r273);
    CPy_DECREF(cpy_r_r274);
    cpy_r_r281 = CPyStatics[10]; /* 'corners' */
    cpy_r_r282 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r281);
    if (unlikely(cpy_r_r282 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 56, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_r283 = PyObject_SetItem(cpy_r_r282, cpy_r_k, cpy_r_r280);
    CPy_DECREF(cpy_r_r282);
    CPy_DECREF(cpy_r_k);
    CPy_DECREF(cpy_r_r280);
    cpy_r_r284 = cpy_r_r283 >= 0;
    if (unlikely(!cpy_r_r284)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 56, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r285 = cpy_r_r270 + 2;
    cpy_r_r270 = cpy_r_r285;
    cpy_r_r286 = CPyTagged_StealAsObject(cpy_r_r285);
    cpy_r_k = cpy_r_r286;
    goto CPyL105;
CPyL113: ;
    cpy_r_r287 = CPyStatic_globals;
    cpy_r_r288 = CPyStatics[11]; /* 'CubeTree' */
    cpy_r_r289 = CPyDict_GetItem(cpy_r_r287, cpy_r_r288);
    if (unlikely(cpy_r_r289 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 58, CPyStatic_globals);
        goto CPyL204;
    }
    PyObject *cpy_r_r290[1] = {cpy_r_r6};
    cpy_r_r291 = (PyObject **)&cpy_r_r290;
    cpy_r_r292 = _PyObject_Vectorcall(cpy_r_r289, cpy_r_r291, 1, 0);
    CPy_DECREF(cpy_r_r289);
    if (unlikely(cpy_r_r292 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 58, CPyStatic_globals);
        goto CPyL204;
    }
    cpy_r_r293 = CPyStatics[19]; /* 0 */
    CPy_INCREF(cpy_r_r293);
    cpy_r_depth_limit = cpy_r_r293;
CPyL116: ;
    if (!1) goto CPyL205;
    cpy_r_r294 = CPyStatics[12]; /* 'Current Depth' */
    cpy_r_r295 = CPyModule_builtins;
    cpy_r_r296 = CPyStatics[8]; /* 'print' */
    cpy_r_r297 = CPyObject_GetAttr(cpy_r_r295, cpy_r_r296);
    if (unlikely(cpy_r_r297 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 61, CPyStatic_globals);
        goto CPyL206;
    }
    PyObject *cpy_r_r298[2] = {cpy_r_r294, cpy_r_depth_limit};
    cpy_r_r299 = (PyObject **)&cpy_r_r298;
    cpy_r_r300 = _PyObject_Vectorcall(cpy_r_r297, cpy_r_r299, 2, 0);
    CPy_DECREF(cpy_r_r297);
    if (unlikely(cpy_r_r300 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 61, CPyStatic_globals);
        goto CPyL206;
    } else
        goto CPyL207;
CPyL119: ;
    cpy_r_r301 = CPyStatic_globals;
    cpy_r_r302 = CPyStatics[11]; /* 'CubeTree' */
    cpy_r_r303 = CPyDict_GetItem(cpy_r_r301, cpy_r_r302);
    if (unlikely(cpy_r_r303 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 62, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r304 = CPyStatics[13]; /* 'corner_dfs' */
    PyObject *cpy_r_r305[3] = {cpy_r_r303, cpy_r_r292, cpy_r_depth_limit};
    cpy_r_r306 = (PyObject **)&cpy_r_r305;
    cpy_r_r307 = PyObject_VectorcallMethod(cpy_r_r304, cpy_r_r306, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r307 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 62, CPyStatic_globals);
        goto CPyL208;
    }
    CPy_DECREF(cpy_r_r303);
    cpy_r_r308 = PyObject_IsTrue(cpy_r_r307);
    CPy_DECREF(cpy_r_r307);
    cpy_r_r309 = cpy_r_r308 >= 0;
    if (unlikely(!cpy_r_r309)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 62, CPyStatic_globals);
        goto CPyL206;
    }
    cpy_r_r310 = cpy_r_r308;
    if (cpy_r_r310) {
        goto CPyL209;
    } else
        goto CPyL126;
CPyL123: ;
    cpy_r_r311 = CPyStatics[14]; /* 'Depth for given position' */
    cpy_r_r312 = CPyModule_builtins;
    cpy_r_r313 = CPyStatics[8]; /* 'print' */
    cpy_r_r314 = CPyObject_GetAttr(cpy_r_r312, cpy_r_r313);
    if (unlikely(cpy_r_r314 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 65, CPyStatic_globals);
        goto CPyL210;
    }
    PyObject *cpy_r_r315[2] = {cpy_r_r311, cpy_r_depth_limit};
    cpy_r_r316 = (PyObject **)&cpy_r_r315;
    cpy_r_r317 = _PyObject_Vectorcall(cpy_r_r314, cpy_r_r316, 2, 0);
    CPy_DECREF(cpy_r_r314);
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 65, CPyStatic_globals);
        goto CPyL210;
    } else
        goto CPyL211;
CPyL125: ;
    CPy_DECREF(cpy_r_depth_limit);
    goto CPyL99;
CPyL126: ;
    cpy_r_r318 = CPyStatics[20]; /* 1 */
    cpy_r_r319 = PyNumber_InPlaceAdd(cpy_r_depth_limit, cpy_r_r318);
    CPy_DECREF(cpy_r_depth_limit);
    if (unlikely(cpy_r_r319 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 68, CPyStatic_globals);
        goto CPyL212;
    }
    cpy_r_depth_limit = cpy_r_r319;
    goto CPyL116;
CPyL128: ;
    cpy_r_r320 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r320)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 51, CPyStatic_globals);
        goto CPyL213;
    } else
        goto CPyL97;
CPyL129: ;
    cpy_r_r321 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r321)) {
        CPy_AddTraceback("pattern_database.py", "create_corner_database", 50, CPyStatic_globals);
        goto CPyL131;
    }
    cpy_r_r322 = Py_None;
    CPy_INCREF(cpy_r_r322);
    return cpy_r_r322;
CPyL131: ;
    cpy_r_r323 = NULL;
    return cpy_r_r323;
CPyL132: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL131;
CPyL133: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL131;
CPyL134: ;
    CPy_DECREF(cpy_r_i);
    goto CPyL7;
CPyL135: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    goto CPyL131;
CPyL136: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    goto CPyL131;
CPyL137: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    goto CPyL131;
CPyL138: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    goto CPyL131;
CPyL139: ;
    CPy_DECREF(cpy_r_corners);
    CPy_DECREF(cpy_r_r18);
    goto CPyL58;
CPyL140: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    goto CPyL131;
CPyL141: ;
    CPy_DECREF(cpy_r_r23);
    goto CPyL12;
CPyL142: ;
    CPy_DECREF(cpy_r_r24);
    goto CPyL55;
CPyL143: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    goto CPyL131;
CPyL144: ;
    CPy_DECREF(cpy_r_r29);
    goto CPyL15;
CPyL145: ;
    CPy_DECREF(cpy_r_r30);
    goto CPyL52;
CPyL146: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    goto CPyL131;
CPyL147: ;
    CPy_DECREF(cpy_r_r35);
    goto CPyL18;
CPyL148: ;
    CPy_DECREF(cpy_r_r36);
    goto CPyL49;
CPyL149: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_d);
    goto CPyL131;
CPyL150: ;
    CPy_DECREF(cpy_r_r41);
    goto CPyL21;
CPyL151: ;
    CPy_DECREF(cpy_r_r42);
    goto CPyL46;
CPyL152: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_e);
    goto CPyL131;
CPyL153: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL24;
CPyL154: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL43;
CPyL155: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_f);
    goto CPyL131;
CPyL156: ;
    CPy_DECREF(cpy_r_r53);
    goto CPyL27;
CPyL157: ;
    CPy_DECREF(cpy_r_r54);
    goto CPyL40;
CPyL158: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r54);
    CPy_DecRef(cpy_r_g);
    goto CPyL131;
CPyL159: ;
    CPy_DECREF(cpy_r_r59);
    goto CPyL30;
CPyL160: ;
    CPy_DECREF(cpy_r_r60);
    goto CPyL37;
CPyL161: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r54);
    CPy_DecRef(cpy_r_g);
    CPy_DecRef(cpy_r_r60);
    CPy_DecRef(cpy_r_r61);
    goto CPyL131;
CPyL162: ;
    CPy_DECREF(cpy_r_r65);
    goto CPyL33;
CPyL163: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corners);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_r42);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r54);
    CPy_DecRef(cpy_r_g);
    CPy_DecRef(cpy_r_r60);
    CPy_DecRef(cpy_r_r61);
    CPy_DecRef(cpy_r_r66);
    goto CPyL131;
CPyL164: ;
    CPy_DECREF(cpy_r_r79);
    goto CPyL35;
CPyL165: ;
    CPy_DECREF(cpy_r_r83);
    goto CPyL36;
CPyL166: ;
    CPy_DECREF(cpy_r_r88);
    goto CPyL39;
CPyL167: ;
    CPy_DECREF(cpy_r_r93);
    goto CPyL42;
CPyL168: ;
    CPy_DECREF(cpy_r_r98);
    goto CPyL45;
CPyL169: ;
    CPy_DECREF(cpy_r_r103);
    goto CPyL48;
CPyL170: ;
    CPy_DECREF(cpy_r_r108);
    goto CPyL51;
CPyL171: ;
    CPy_DECREF(cpy_r_r113);
    goto CPyL54;
CPyL172: ;
    CPy_DECREF(cpy_r_r118);
    goto CPyL57;
CPyL173: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    goto CPyL131;
CPyL174: ;
    CPy_DECREF(cpy_r_r120);
    goto CPyL96;
CPyL175: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_r120);
    goto CPyL131;
CPyL176: ;
    CPy_DECREF(cpy_r_a);
    CPy_DECREF(cpy_r_r134);
    goto CPyL95;
CPyL177: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    goto CPyL131;
CPyL178: ;
    CPy_DECREF(cpy_r_b);
    CPy_DECREF(cpy_r_r148);
    goto CPyL94;
CPyL179: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    goto CPyL131;
CPyL180: ;
    CPy_DECREF(cpy_r_c);
    CPy_DECREF(cpy_r_r162);
    goto CPyL93;
CPyL181: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    CPy_DecRef(cpy_r_r162);
    goto CPyL131;
CPyL182: ;
    CPy_DECREF(cpy_r_d);
    CPy_DECREF(cpy_r_r176);
    goto CPyL92;
CPyL183: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r176);
    goto CPyL131;
CPyL184: ;
    CPy_DECREF(cpy_r_e);
    CPy_DECREF(cpy_r_r190);
    goto CPyL91;
CPyL185: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r176);
    CPy_DecRef(cpy_r_r190);
    goto CPyL131;
CPyL186: ;
    CPy_DECREF(cpy_r_f);
    CPy_DECREF(cpy_r_r204);
    goto CPyL90;
CPyL187: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_g);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r176);
    CPy_DecRef(cpy_r_r190);
    CPy_DecRef(cpy_r_r204);
    goto CPyL131;
CPyL188: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r176);
    CPy_DecRef(cpy_r_r190);
    CPy_DecRef(cpy_r_r204);
    CPy_DecRef(cpy_r_c_orientation);
    goto CPyL131;
CPyL189: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_corner_permutation);
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    CPy_DecRef(cpy_r_c);
    CPy_DecRef(cpy_r_d);
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r120);
    CPy_DecRef(cpy_r_r134);
    CPy_DecRef(cpy_r_r148);
    CPy_DecRef(cpy_r_r162);
    CPy_DecRef(cpy_r_r176);
    CPy_DecRef(cpy_r_r190);
    CPy_DecRef(cpy_r_r204);
    CPy_DecRef(cpy_r_c_orientation);
    CPy_DecRef(cpy_r_r238);
    goto CPyL131;
CPyL190: ;
    CPy_DECREF(cpy_r_r242);
    goto CPyL87;
CPyL191: ;
    CPy_DECREF(cpy_r_r246);
    goto CPyL88;
CPyL192: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    goto CPyL131;
CPyL193: ;
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_corner_orientations);
    CPy_DECREF(cpy_r_r254);
    goto CPyL129;
CPyL194: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    goto CPyL131;
CPyL195: ;
    CPy_DECREF(cpy_r_r255);
    CPy_DECREF(cpy_r_r256);
    goto CPyL128;
CPyL196: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r257);
    goto CPyL131;
CPyL197: ;
    CPy_DECREF(cpy_r_r263);
    goto CPyL102;
CPyL198: ;
    CPy_DECREF(cpy_r_r269);
    goto CPyL104;
CPyL199: ;
    CPy_DECREF(cpy_r_r257);
    CPy_DECREF(cpy_r_k);
    goto CPyL113;
CPyL200: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_k);
    goto CPyL131;
CPyL201: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_k);
    CPy_DecRef(cpy_r_r273);
    goto CPyL131;
CPyL202: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_k);
    CPy_DecRef(cpy_r_r273);
    CPy_DecRef(cpy_r_r274);
    goto CPyL131;
CPyL203: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r257);
    CPy_DecRef(cpy_r_k);
    CPy_DecRef(cpy_r_r280);
    goto CPyL131;
CPyL204: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    goto CPyL131;
CPyL205: ;
    CPy_DECREF(cpy_r_r292);
    CPy_DECREF(cpy_r_depth_limit);
    goto CPyL99;
CPyL206: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r292);
    CPy_DecRef(cpy_r_depth_limit);
    goto CPyL131;
CPyL207: ;
    CPy_DECREF(cpy_r_r300);
    goto CPyL119;
CPyL208: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r292);
    CPy_DecRef(cpy_r_depth_limit);
    CPy_DecRef(cpy_r_r303);
    goto CPyL131;
CPyL209: ;
    CPy_DECREF(cpy_r_r292);
    goto CPyL123;
CPyL210: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_depth_limit);
    goto CPyL131;
CPyL211: ;
    CPy_DECREF(cpy_r_r317);
    goto CPyL125;
CPyL212: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    CPy_DecRef(cpy_r_r255);
    CPy_DecRef(cpy_r_r256);
    CPy_DecRef(cpy_r_r292);
    goto CPyL131;
CPyL213: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_corner_orientations);
    CPy_DecRef(cpy_r_r254);
    goto CPyL131;
}

PyObject *CPyPy_create_corner_database(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":create_corner_database", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *retval = CPyDef_create_corner_database();
    return retval;
fail: ;
    CPy_AddTraceback("pattern_database.py", "create_corner_database", 5, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r15;
    void *cpy_r_r17;
    void *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[15]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "<module>", -1, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyModule_Cube;
    cpy_r_r6 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r7 = cpy_r_r5 != cpy_r_r6;
    if (cpy_r_r7) goto CPyL6;
    cpy_r_r8 = CPyStatics[3]; /* 'Cube' */
    cpy_r_r9 = PyImport_Import(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "<module>", 1, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_Cube = cpy_r_r9;
    CPy_INCREF(CPyModule_Cube);
    CPy_DECREF(cpy_r_r9);
CPyL6: ;
    cpy_r_r10 = CPyModule_CubeTree;
    cpy_r_r11 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r12 = cpy_r_r10 != cpy_r_r11;
    if (cpy_r_r12) goto CPyL9;
    cpy_r_r13 = CPyStatics[11]; /* 'CubeTree' */
    cpy_r_r14 = PyImport_Import(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "<module>", 2, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_CubeTree = cpy_r_r14;
    CPy_INCREF(CPyModule_CubeTree);
    CPy_DECREF(cpy_r_r14);
CPyL9: ;
    cpy_r_r15 = (PyObject **)&CPyModule_random;
    PyObject **cpy_r_r16[1] = {cpy_r_r15};
    cpy_r_r17 = (void *)&cpy_r_r16;
    int64_t cpy_r_r18[1] = {3};
    cpy_r_r19 = (void *)&cpy_r_r18;
    cpy_r_r20 = CPyStatics[24]; /* (('random', 'random', 'random'),) */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyStatics[17]; /* 'pattern_database.py' */
    cpy_r_r23 = CPyStatics[18]; /* '<module>' */
    cpy_r_r24 = CPyImport_ImportMany(cpy_r_r20, cpy_r_r17, cpy_r_r21, cpy_r_r22, cpy_r_r23, cpy_r_r19);
    if (!cpy_r_r24) goto CPyL12;
    cpy_r_r25 = CPyDef_create_corner_database();
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("pattern_database.py", "<module>", 71, CPyStatic_globals);
        goto CPyL12;
    } else
        goto CPyL13;
CPyL11: ;
    return 1;
CPyL12: ;
    cpy_r_r26 = 2;
    return cpy_r_r26;
CPyL13: ;
    CPy_DECREF(cpy_r_r25);
    goto CPyL11;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_pattern_database = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_Cube = Py_None;
    CPyModule_CubeTree = Py_None;
    CPyModule_random = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[25];
const char * const CPyLit_Str[] = {
    "\b\004Cube\022create_solved_cube\006remove\006append\003sum\005print\005cubie\acorners",
    "\005\bCubeTree\rCurrent Depth\ncorner_dfs\030Depth for given position\bbuiltins",
    "\003\006random\023pattern_database.py\b<module>",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0040\0001\0002\0003",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {2, 3, 16, 16, 16, 1, 23};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_pattern_database_internal = NULL;
CPyModule *CPyModule_pattern_database;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_Cube;
CPyModule *CPyModule_CubeTree;
CPyModule *CPyModule_random;
PyObject *CPyDef_create_corner_database(void);
PyObject *CPyPy_create_corner_database(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
