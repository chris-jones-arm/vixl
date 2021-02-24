// Copyright 2020, VIXL authors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of ARM Limited nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Initialisation data for a std::map, from instruction form to the visitor
// function that handles it. This allows reuse of existing visitor functions
// that support groups of instructions, though they may do extra decoding
// no longer needed.
// In the long term, it's expected that each component that uses the decoder
// will want to group instruction handling in the way most appropriate to
// the component's function, so this map initialisation will no longer be
// shared.

#define DEFAULT_FORM_TO_VISITOR_MAP(VISITORCLASS)                              \
  {"abs_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},          \
      {"addpl_r_ri", &VISITORCLASS::VisitSVEStackFrameAdjustment},             \
      {"addvl_r_ri", &VISITORCLASS::VisitSVEStackFrameAdjustment},             \
      {"add_z_p_zz", &VISITORCLASS::VisitSVEIntAddSubtractVectors_Predicated}, \
      {"add_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},     \
      {"add_z_zz", &VISITORCLASS::VisitSVEIntArithmeticUnpredicated},          \
      {"adr_z_az_d_s32_scaled", &VISITORCLASS::VisitSVEAddressGeneration},     \
      {"adr_z_az_d_u32_scaled", &VISITORCLASS::VisitSVEAddressGeneration},     \
      {"adr_z_az_sd_same_scaled", &VISITORCLASS::VisitSVEAddressGeneration},   \
      {"ands_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"andv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                     \
      {"and_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},               \
      {"and_z_p_zz", &VISITORCLASS::VisitSVEBitwiseLogical_Predicated},        \
      {"and_z_zi", &VISITORCLASS::VisitSVEBitwiseLogicalWithImm_Unpredicated}, \
      {"and_z_zz", &VISITORCLASS::VisitSVEBitwiseLogicalUnpredicated},         \
      {"asrd_z_p_zi", &VISITORCLASS::VisitSVEBitwiseShiftByImm_Predicated},    \
      {"asrr_z_p_zz", &VISITORCLASS::VisitSVEBitwiseShiftByVector_Predicated}, \
      {"asr_z_p_zi", &VISITORCLASS::VisitSVEBitwiseShiftByImm_Predicated},     \
      {"asr_z_p_zw",                                                           \
       &VISITORCLASS::VisitSVEBitwiseShiftByWideElements_Predicated},          \
      {"asr_z_p_zz", &VISITORCLASS::VisitSVEBitwiseShiftByVector_Predicated},  \
      {"asr_z_zi", &VISITORCLASS::VisitSVEBitwiseShiftUnpredicated},           \
      {"asr_z_zw", &VISITORCLASS::VisitSVEBitwiseShiftUnpredicated},           \
      {"bics_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"bic_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},               \
      {"bic_z_p_zz", &VISITORCLASS::VisitSVEBitwiseLogical_Predicated},        \
      {"bic_z_zz", &VISITORCLASS::VisitSVEBitwiseLogicalUnpredicated},         \
      {"brkas_p_p_p_z", &VISITORCLASS::VisitSVEPartitionBreakCondition},       \
      {"brka_p_p_p", &VISITORCLASS::VisitSVEPartitionBreakCondition},          \
      {"brkbs_p_p_p_z", &VISITORCLASS::VisitSVEPartitionBreakCondition},       \
      {"brkb_p_p_p", &VISITORCLASS::VisitSVEPartitionBreakCondition},          \
      {"brkns_p_p_pp", &VISITORCLASS::VisitSVEPropagateBreakToNextPartition},  \
      {"brkn_p_p_pp", &VISITORCLASS::VisitSVEPropagateBreakToNextPartition},   \
      {"brkpas_p_p_pp", &VISITORCLASS::VisitSVEPropagateBreak},                \
      {"brkpa_p_p_pp", &VISITORCLASS::VisitSVEPropagateBreak},                 \
      {"brkpbs_p_p_pp", &VISITORCLASS::VisitSVEPropagateBreak},                \
      {"brkpb_p_p_pp", &VISITORCLASS::VisitSVEPropagateBreak},                 \
      {"clasta_r_p_z",                                                         \
       &VISITORCLASS::VisitSVEConditionallyExtractElementToGeneralRegister},   \
      {"clasta_v_p_z",                                                         \
       &VISITORCLASS::VisitSVEConditionallyExtractElementToSIMDFPScalar},      \
      {"clasta_z_p_zz",                                                        \
       &VISITORCLASS::VisitSVEConditionallyBroadcastElementToVector},          \
      {"clastb_r_p_z",                                                         \
       &VISITORCLASS::VisitSVEConditionallyExtractElementToGeneralRegister},   \
      {"clastb_v_p_z",                                                         \
       &VISITORCLASS::VisitSVEConditionallyExtractElementToSIMDFPScalar},      \
      {"clastb_z_p_zz",                                                        \
       &VISITORCLASS::VisitSVEConditionallyBroadcastElementToVector},          \
      {"cls_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},      \
      {"clz_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},      \
      {"cmpeq_p_p_zi", &VISITORCLASS::VisitSVEIntCompareSignedImm},            \
      {"cmpeq_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpeq_p_p_zz", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpge_p_p_zi", &VISITORCLASS::VisitSVEIntCompareSignedImm},            \
      {"cmpge_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpge_p_p_zz", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpgt_p_p_zi", &VISITORCLASS::VisitSVEIntCompareSignedImm},            \
      {"cmpgt_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpgt_p_p_zz", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmphi_p_p_zi", &VISITORCLASS::VisitSVEIntCompareUnsignedImm},          \
      {"cmphi_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmphi_p_p_zz", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmphs_p_p_zi", &VISITORCLASS::VisitSVEIntCompareUnsignedImm},          \
      {"cmphs_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmphs_p_p_zz", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmple_p_p_zi", &VISITORCLASS::VisitSVEIntCompareSignedImm},            \
      {"cmple_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmplo_p_p_zi", &VISITORCLASS::VisitSVEIntCompareUnsignedImm},          \
      {"cmplo_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpls_p_p_zi", &VISITORCLASS::VisitSVEIntCompareUnsignedImm},          \
      {"cmpls_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmplt_p_p_zi", &VISITORCLASS::VisitSVEIntCompareSignedImm},            \
      {"cmplt_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpne_p_p_zi", &VISITORCLASS::VisitSVEIntCompareSignedImm},            \
      {"cmpne_p_p_zw", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cmpne_p_p_zz", &VISITORCLASS::VisitSVEIntCompareVectors},              \
      {"cnot_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"cntb_r_s", &VISITORCLASS::VisitSVEElementCount},                       \
      {"cntd_r_s", &VISITORCLASS::VisitSVEElementCount},                       \
      {"cnth_r_s", &VISITORCLASS::VisitSVEElementCount},                       \
      {"cntp_r_p_p", &VISITORCLASS::VisitSVEPredicateCount},                   \
      {"cntw_r_s", &VISITORCLASS::VisitSVEElementCount},                       \
      {"cnt_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},      \
      {"compact_z_p_z", &VISITORCLASS::VisitSVECompressActiveElements},        \
      {"cpy_z_o_i", &VISITORCLASS::VisitSVECopyIntImm_Predicated},             \
      {"cpy_z_p_i", &VISITORCLASS::VisitSVECopyIntImm_Predicated},             \
      {"cpy_z_p_r",                                                            \
       &VISITORCLASS::VisitSVECopyGeneralRegisterToVector_Predicated},         \
      {"cpy_z_p_v",                                                            \
       &VISITORCLASS::VisitSVECopySIMDFPScalarRegisterToVector_Predicated},    \
      {"ctermeq_rr", &VISITORCLASS::VisitSVEConditionallyTerminateScalars},    \
      {"ctermne_rr", &VISITORCLASS::VisitSVEConditionallyTerminateScalars},    \
      {"decb_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"decd_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"decd_z_zs", &VISITORCLASS::VisitSVEIncDecVectorByElementCount},        \
      {"dech_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"dech_z_zs", &VISITORCLASS::VisitSVEIncDecVectorByElementCount},        \
      {"decp_r_p_r", &VISITORCLASS::VisitSVEIncDecByPredicateCount},           \
      {"decp_z_p_z", &VISITORCLASS::VisitSVEIncDecByPredicateCount},           \
      {"decw_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"decw_z_zs", &VISITORCLASS::VisitSVEIncDecVectorByElementCount},        \
      {"dupm_z_i", &VISITORCLASS::VisitSVEBroadcastBitmaskImm},                \
      {"dup_z_i", &VISITORCLASS::VisitSVEBroadcastIntImm_Unpredicated},        \
      {"dup_z_r", &VISITORCLASS::VisitSVEBroadcastGeneralRegister},            \
      {"dup_z_zi", &VISITORCLASS::VisitSVEBroadcastIndexElement},              \
      {"eors_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"eorv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                     \
      {"eor_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},               \
      {"eor_z_p_zz", &VISITORCLASS::VisitSVEBitwiseLogical_Predicated},        \
      {"eor_z_zi", &VISITORCLASS::VisitSVEBitwiseLogicalWithImm_Unpredicated}, \
      {"eor_z_zz", &VISITORCLASS::VisitSVEBitwiseLogicalUnpredicated},         \
      {"ext_z_zi_des", &VISITORCLASS::VisitSVEPermuteVectorExtract},           \
      {"fabd_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fabs_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"facge_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"facgt_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"fadda_v_p_z", &VISITORCLASS::VisitSVEFPAccumulatingReduction},         \
      {"faddv_v_p_z", &VISITORCLASS::VisitSVEFPFastReduction},                 \
      {"fadd_z_p_zs", &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},  \
      {"fadd_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fadd_z_zz", &VISITORCLASS::VisitSVEFPArithmeticUnpredicated},          \
      {"fcadd_z_p_zz", &VISITORCLASS::VisitSVEFPComplexAddition},              \
      {"fcmeq_p_p_z0", &VISITORCLASS::VisitSVEFPCompareWithZero},              \
      {"fcmeq_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"fcmge_p_p_z0", &VISITORCLASS::VisitSVEFPCompareWithZero},              \
      {"fcmge_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"fcmgt_p_p_z0", &VISITORCLASS::VisitSVEFPCompareWithZero},              \
      {"fcmgt_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"fcmla_z_p_zzz", &VISITORCLASS::VisitSVEFPComplexMulAdd},               \
      {"fcmla_z_zzzi_h", &VISITORCLASS::VisitSVEFPComplexMulAddIndex},         \
      {"fcmla_z_zzzi_s", &VISITORCLASS::VisitSVEFPComplexMulAddIndex},         \
      {"fcmle_p_p_z0", &VISITORCLASS::VisitSVEFPCompareWithZero},              \
      {"fcmlt_p_p_z0", &VISITORCLASS::VisitSVEFPCompareWithZero},              \
      {"fcmne_p_p_z0", &VISITORCLASS::VisitSVEFPCompareWithZero},              \
      {"fcmne_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"fcmuo_p_p_zz", &VISITORCLASS::VisitSVEFPCompareVectors},               \
      {"fcpy_z_p_i", &VISITORCLASS::VisitSVECopyFPImm_Predicated},             \
      {"fcvtzs_z_p_z_d2w", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzs_z_p_z_d2x", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzs_z_p_z_fp162h", &VISITORCLASS::VisitSVEFPConvertToInt},          \
      {"fcvtzs_z_p_z_fp162w", &VISITORCLASS::VisitSVEFPConvertToInt},          \
      {"fcvtzs_z_p_z_fp162x", &VISITORCLASS::VisitSVEFPConvertToInt},          \
      {"fcvtzs_z_p_z_s2w", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzs_z_p_z_s2x", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzu_z_p_z_d2w", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzu_z_p_z_d2x", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzu_z_p_z_fp162h", &VISITORCLASS::VisitSVEFPConvertToInt},          \
      {"fcvtzu_z_p_z_fp162w", &VISITORCLASS::VisitSVEFPConvertToInt},          \
      {"fcvtzu_z_p_z_fp162x", &VISITORCLASS::VisitSVEFPConvertToInt},          \
      {"fcvtzu_z_p_z_s2w", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvtzu_z_p_z_s2x", &VISITORCLASS::VisitSVEFPConvertToInt},             \
      {"fcvt_z_p_z_d2h", &VISITORCLASS::VisitSVEFPConvertPrecision},           \
      {"fcvt_z_p_z_d2s", &VISITORCLASS::VisitSVEFPConvertPrecision},           \
      {"fcvt_z_p_z_h2d", &VISITORCLASS::VisitSVEFPConvertPrecision},           \
      {"fcvt_z_p_z_h2s", &VISITORCLASS::VisitSVEFPConvertPrecision},           \
      {"fcvt_z_p_z_s2d", &VISITORCLASS::VisitSVEFPConvertPrecision},           \
      {"fcvt_z_p_z_s2h", &VISITORCLASS::VisitSVEFPConvertPrecision},           \
      {"fdivr_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},        \
      {"fdiv_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fdup_z_i", &VISITORCLASS::VisitSVEBroadcastFPImm_Unpredicated},        \
      {"fexpa_z_z", &VISITORCLASS::VisitSVEFPExponentialAccelerator},          \
      {"fmad_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                       \
      {"fmaxnmv_v_p_z", &VISITORCLASS::VisitSVEFPFastReduction},               \
      {"fmaxnm_z_p_zs",                                                        \
       &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},                 \
      {"fmaxnm_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},       \
      {"fmaxv_v_p_z", &VISITORCLASS::VisitSVEFPFastReduction},                 \
      {"fmax_z_p_zs", &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},  \
      {"fmax_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fminnmv_v_p_z", &VISITORCLASS::VisitSVEFPFastReduction},               \
      {"fminnm_z_p_zs",                                                        \
       &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},                 \
      {"fminnm_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},       \
      {"fminv_v_p_z", &VISITORCLASS::VisitSVEFPFastReduction},                 \
      {"fmin_z_p_zs", &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},  \
      {"fmin_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fmla_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                       \
      {"fmla_z_zzzi_d", &VISITORCLASS::VisitSVEFPMulAddIndex},                 \
      {"fmla_z_zzzi_h", &VISITORCLASS::VisitSVEFPMulAddIndex},                 \
      {"fmla_z_zzzi_s", &VISITORCLASS::VisitSVEFPMulAddIndex},                 \
      {"fmls_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                       \
      {"fmls_z_zzzi_d", &VISITORCLASS::VisitSVEFPMulAddIndex},                 \
      {"fmls_z_zzzi_h", &VISITORCLASS::VisitSVEFPMulAddIndex},                 \
      {"fmls_z_zzzi_s", &VISITORCLASS::VisitSVEFPMulAddIndex},                 \
      {"fmsb_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                       \
      {"fmulx_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},        \
      {"fmul_z_p_zs", &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},  \
      {"fmul_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fmul_z_zz", &VISITORCLASS::VisitSVEFPArithmeticUnpredicated},          \
      {"fmul_z_zzi_d", &VISITORCLASS::VisitSVEFPMulIndex},                     \
      {"fmul_z_zzi_h", &VISITORCLASS::VisitSVEFPMulIndex},                     \
      {"fmul_z_zzi_s", &VISITORCLASS::VisitSVEFPMulIndex},                     \
      {"fneg_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"fnmad_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                      \
      {"fnmla_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                      \
      {"fnmls_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                      \
      {"fnmsb_z_p_zzz", &VISITORCLASS::VisitSVEFPMulAdd},                      \
      {"frecpe_z_z", &VISITORCLASS::VisitSVEFPUnaryOpUnpredicated},            \
      {"frecps_z_zz", &VISITORCLASS::VisitSVEFPArithmeticUnpredicated},        \
      {"frecpx_z_p_z", &VISITORCLASS::VisitSVEFPUnaryOp},                      \
      {"frinta_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frinti_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frintm_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frintn_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frintp_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frintx_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frintz_z_p_z", &VISITORCLASS::VisitSVEFPRoundToIntegralValue},         \
      {"frsqrte_z_z", &VISITORCLASS::VisitSVEFPUnaryOpUnpredicated},           \
      {"frsqrts_z_zz", &VISITORCLASS::VisitSVEFPArithmeticUnpredicated},       \
      {"fscale_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},       \
      {"fsqrt_z_p_z", &VISITORCLASS::VisitSVEFPUnaryOp},                       \
      {"fsubr_z_p_zs", &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated}, \
      {"fsubr_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},        \
      {"fsub_z_p_zs", &VISITORCLASS::VisitSVEFPArithmeticWithImm_Predicated},  \
      {"fsub_z_p_zz", &VISITORCLASS::VisitSVEFPArithmetic_Predicated},         \
      {"fsub_z_zz", &VISITORCLASS::VisitSVEFPArithmeticUnpredicated},          \
      {"ftmad_z_zzi", &VISITORCLASS::VisitSVEFPTrigMulAddCoefficient},         \
      {"ftsmul_z_zz", &VISITORCLASS::VisitSVEFPArithmeticUnpredicated},        \
      {"ftssel_z_zz", &VISITORCLASS::VisitSVEFPTrigSelectCoefficient},         \
      {"incb_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"incd_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"incd_z_zs", &VISITORCLASS::VisitSVEIncDecVectorByElementCount},        \
      {"inch_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"inch_z_zs", &VISITORCLASS::VisitSVEIncDecVectorByElementCount},        \
      {"incp_r_p_r", &VISITORCLASS::VisitSVEIncDecByPredicateCount},           \
      {"incp_z_p_z", &VISITORCLASS::VisitSVEIncDecByPredicateCount},           \
      {"incw_r_rs", &VISITORCLASS::VisitSVEIncDecRegisterByElementCount},      \
      {"incw_z_zs", &VISITORCLASS::VisitSVEIncDecVectorByElementCount},        \
      {"index_z_ii", &VISITORCLASS::VisitSVEIndexGeneration},                  \
      {"index_z_ir", &VISITORCLASS::VisitSVEIndexGeneration},                  \
      {"index_z_ri", &VISITORCLASS::VisitSVEIndexGeneration},                  \
      {"index_z_rr", &VISITORCLASS::VisitSVEIndexGeneration},                  \
      {"insr_z_r", &VISITORCLASS::VisitSVEInsertGeneralRegister},              \
      {"insr_z_v", &VISITORCLASS::VisitSVEInsertSIMDFPScalarRegister},         \
      {"lasta_r_p_z", &VISITORCLASS::VisitSVEExtractElementToGeneralRegister}, \
      {"lasta_v_p_z",                                                          \
       &VISITORCLASS::VisitSVEExtractElementToSIMDFPScalarRegister},           \
      {"lastb_r_p_z", &VISITORCLASS::VisitSVEExtractElementToGeneralRegister}, \
      {"lastb_v_p_z",                                                          \
       &VISITORCLASS::VisitSVEExtractElementToSIMDFPScalarRegister},           \
      {"ld1b_z_p_ai_d", &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm}, \
      {"ld1b_z_p_ai_s", &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm}, \
      {"ld1b_z_p_bi_u16",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1b_z_p_bi_u32",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1b_z_p_bi_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1b_z_p_bi_u8", &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm}, \
      {"ld1b_z_p_br_u16",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1b_z_p_br_u32",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1b_z_p_br_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1b_z_p_br_u8",                                                       \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1b_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1b_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1b_z_p_bz_s_x32_unscaled",                                           \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ld1d_z_p_ai_d", &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm}, \
      {"ld1d_z_p_bi_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1d_z_p_br_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1d_z_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ld1d_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1d_z_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ld1d_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1h_z_p_ai_d", &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm}, \
      {"ld1h_z_p_ai_s", &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm}, \
      {"ld1h_z_p_bi_u16",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1h_z_p_bi_u32",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1h_z_p_bi_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1h_z_p_br_u16",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1h_z_p_br_u32",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1h_z_p_br_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1h_z_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ld1h_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1h_z_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ld1h_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1h_z_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherLoadHalfwords_ScalarPlus32BitScaledOffsets},     \
      {"ld1h_z_p_bz_s_x32_unscaled",                                           \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ld1rb_z_p_bi_u16", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rb_z_p_bi_u32", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rb_z_p_bi_u64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rb_z_p_bi_u8", &VISITORCLASS::VisitSVELoadAndBroadcastElement},     \
      {"ld1rd_z_p_bi_u64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rh_z_p_bi_u16", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rh_z_p_bi_u32", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rh_z_p_bi_u64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rqb_z_p_bi_u8",                                                     \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusImm},         \
      {"ld1rqb_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusScalar},      \
      {"ld1rqd_z_p_bi_u64",                                                    \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusImm},         \
      {"ld1rqd_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusScalar},      \
      {"ld1rqh_z_p_bi_u16",                                                    \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusImm},         \
      {"ld1rqh_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusScalar},      \
      {"ld1rqw_z_p_bi_u32",                                                    \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusImm},         \
      {"ld1rqw_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVELoadAndBroadcastQuadword_ScalarPlusScalar},      \
      {"ld1rsb_z_p_bi_s16", &VISITORCLASS::VisitSVELoadAndBroadcastElement},   \
      {"ld1rsb_z_p_bi_s32", &VISITORCLASS::VisitSVELoadAndBroadcastElement},   \
      {"ld1rsb_z_p_bi_s64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},   \
      {"ld1rsh_z_p_bi_s32", &VISITORCLASS::VisitSVELoadAndBroadcastElement},   \
      {"ld1rsh_z_p_bi_s64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},   \
      {"ld1rsw_z_p_bi_s64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},   \
      {"ld1rw_z_p_bi_u32", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1rw_z_p_bi_u64", &VISITORCLASS::VisitSVELoadAndBroadcastElement},    \
      {"ld1sb_z_p_ai_d",                                                       \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ld1sb_z_p_ai_s",                                                       \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ld1sb_z_p_bi_s16",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1sb_z_p_bi_s32",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1sb_z_p_bi_s64",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1sb_z_p_br_s16",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1sb_z_p_br_s32",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1sb_z_p_br_s64",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1sb_z_p_bz_d_64_unscaled",                                           \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1sb_z_p_bz_d_x32_unscaled",                                          \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1sb_z_p_bz_s_x32_unscaled",                                          \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ld1sh_z_p_ai_d",                                                       \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ld1sh_z_p_ai_s",                                                       \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ld1sh_z_p_bi_s32",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1sh_z_p_bi_s64",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1sh_z_p_br_s32",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1sh_z_p_br_s64",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1sh_z_p_bz_d_64_scaled",                                             \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ld1sh_z_p_bz_d_64_unscaled",                                           \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1sh_z_p_bz_d_x32_scaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ld1sh_z_p_bz_d_x32_unscaled",                                          \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1sh_z_p_bz_s_x32_scaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherLoadHalfwords_ScalarPlus32BitScaledOffsets},     \
      {"ld1sh_z_p_bz_s_x32_unscaled",                                          \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ld1sw_z_p_ai_d",                                                       \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ld1sw_z_p_bi_s64",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1sw_z_p_br_s64",                                                     \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1sw_z_p_bz_d_64_scaled",                                             \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ld1sw_z_p_bz_d_64_unscaled",                                           \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1sw_z_p_bz_d_x32_scaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ld1sw_z_p_bz_d_x32_unscaled",                                          \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1w_z_p_ai_d", &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm}, \
      {"ld1w_z_p_ai_s", &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm}, \
      {"ld1w_z_p_bi_u32",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1w_z_p_bi_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusImm},                   \
      {"ld1w_z_p_br_u32",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1w_z_p_br_u64",                                                      \
       &VISITORCLASS::VisitSVEContiguousLoad_ScalarPlusScalar},                \
      {"ld1w_z_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ld1w_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ld1w_z_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ld1w_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ld1w_z_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherLoadWords_ScalarPlus32BitScaledOffsets},         \
      {"ld1w_z_p_bz_s_x32_unscaled",                                           \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ld2b_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld2b_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld2d_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld2d_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld2h_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld2h_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld2w_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld2w_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld3b_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld3b_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld3d_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld3d_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld3h_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld3h_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld3w_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld3w_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld4b_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld4b_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld4d_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld4d_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld4h_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld4h_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ld4w_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusImm},           \
      {"ld4w_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVELoadMultipleStructures_ScalarPlusScalar},        \
      {"ldff1b_z_p_ai_d",                                                      \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1b_z_p_ai_s",                                                      \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ldff1b_z_p_br_u16",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1b_z_p_br_u32",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1b_z_p_br_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1b_z_p_br_u8",                                                     \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1b_z_p_bz_d_64_unscaled",                                          \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1b_z_p_bz_d_x32_unscaled",                                         \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1b_z_p_bz_s_x32_unscaled",                                         \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ldff1d_z_p_ai_d",                                                      \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1d_z_p_br_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1d_z_p_bz_d_64_scaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ldff1d_z_p_bz_d_64_unscaled",                                          \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1d_z_p_bz_d_x32_scaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ldff1d_z_p_bz_d_x32_unscaled",                                         \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1h_z_p_ai_d",                                                      \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1h_z_p_ai_s",                                                      \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ldff1h_z_p_br_u16",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1h_z_p_br_u32",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1h_z_p_br_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1h_z_p_bz_d_64_scaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ldff1h_z_p_bz_d_64_unscaled",                                          \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1h_z_p_bz_d_x32_scaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ldff1h_z_p_bz_d_x32_unscaled",                                         \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1h_z_p_bz_s_x32_scaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherLoadHalfwords_ScalarPlus32BitScaledOffsets},     \
      {"ldff1h_z_p_bz_s_x32_unscaled",                                         \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ldff1sb_z_p_ai_d",                                                     \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1sb_z_p_ai_s",                                                     \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ldff1sb_z_p_br_s16",                                                   \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1sb_z_p_br_s32",                                                   \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1sb_z_p_br_s64",                                                   \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1sb_z_p_bz_d_64_unscaled",                                         \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1sb_z_p_bz_d_x32_unscaled",                                        \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1sb_z_p_bz_s_x32_unscaled",                                        \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ldff1sh_z_p_ai_d",                                                     \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1sh_z_p_ai_s",                                                     \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ldff1sh_z_p_br_s32",                                                   \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1sh_z_p_br_s64",                                                   \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1sh_z_p_bz_d_64_scaled",                                           \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ldff1sh_z_p_bz_d_64_unscaled",                                         \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1sh_z_p_bz_d_x32_scaled",                                          \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ldff1sh_z_p_bz_d_x32_unscaled",                                        \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1sh_z_p_bz_s_x32_scaled",                                          \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherLoadHalfwords_ScalarPlus32BitScaledOffsets},     \
      {"ldff1sh_z_p_bz_s_x32_unscaled",                                        \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ldff1sw_z_p_ai_d",                                                     \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1sw_z_p_br_s64",                                                   \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1sw_z_p_bz_d_64_scaled",                                           \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ldff1sw_z_p_bz_d_64_unscaled",                                         \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1sw_z_p_bz_d_x32_scaled",                                          \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ldff1sw_z_p_bz_d_x32_unscaled",                                        \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1w_z_p_ai_d",                                                      \
       &VISITORCLASS::VisitSVE64BitGatherLoad_VectorPlusImm},                  \
      {"ldff1w_z_p_ai_s",                                                      \
       &VISITORCLASS::VisitSVE32BitGatherLoad_VectorPlusImm},                  \
      {"ldff1w_z_p_br_u32",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1w_z_p_br_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousFirstFaultLoad_ScalarPlusScalar},      \
      {"ldff1w_z_p_bz_d_64_scaled",                                            \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitScaledOffsets},   \
      {"ldff1w_z_p_bz_d_64_unscaled",                                          \
       &VISITORCLASS::VisitSVE64BitGatherLoad_ScalarPlus64BitUnscaledOffsets}, \
      {"ldff1w_z_p_bz_d_x32_scaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlus32BitUnpackedScaledOffsets},      \
      {"ldff1w_z_p_bz_d_x32_unscaled",                                         \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherLoad_ScalarPlusUnpacked32BitUnscaledOffsets},    \
      {"ldff1w_z_p_bz_s_x32_scaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherLoadWords_ScalarPlus32BitScaledOffsets},         \
      {"ldff1w_z_p_bz_s_x32_unscaled",                                         \
       &VISITORCLASS::VisitSVE32BitGatherLoad_ScalarPlus32BitUnscaledOffsets}, \
      {"ldnf1b_z_p_bi_u16",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1b_z_p_bi_u32",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1b_z_p_bi_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1b_z_p_bi_u8",                                                     \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1d_z_p_bi_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1h_z_p_bi_u16",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1h_z_p_bi_u32",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1h_z_p_bi_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1sb_z_p_bi_s16",                                                   \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1sb_z_p_bi_s32",                                                   \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1sb_z_p_bi_s64",                                                   \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1sh_z_p_bi_s32",                                                   \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1sh_z_p_bi_s64",                                                   \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1sw_z_p_bi_s64",                                                   \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1w_z_p_bi_u32",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnf1w_z_p_bi_u64",                                                    \
       &VISITORCLASS::VisitSVEContiguousNonFaultLoad_ScalarPlusImm},           \
      {"ldnt1b_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusImm},        \
      {"ldnt1b_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusScalar},     \
      {"ldnt1d_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusImm},        \
      {"ldnt1d_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusScalar},     \
      {"ldnt1h_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusImm},        \
      {"ldnt1h_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusScalar},     \
      {"ldnt1w_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusImm},        \
      {"ldnt1w_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalLoad_ScalarPlusScalar},     \
      {"ldr_p_bi", &VISITORCLASS::VisitSVELoadPredicateRegister},              \
      {"ldr_z_bi", &VISITORCLASS::VisitSVELoadVectorRegister},                 \
      {"lslr_z_p_zz", &VISITORCLASS::VisitSVEBitwiseShiftByVector_Predicated}, \
      {"lsl_z_p_zi", &VISITORCLASS::VisitSVEBitwiseShiftByImm_Predicated},     \
      {"lsl_z_p_zw",                                                           \
       &VISITORCLASS::VisitSVEBitwiseShiftByWideElements_Predicated},          \
      {"lsl_z_p_zz", &VISITORCLASS::VisitSVEBitwiseShiftByVector_Predicated},  \
      {"lsl_z_zi", &VISITORCLASS::VisitSVEBitwiseShiftUnpredicated},           \
      {"lsl_z_zw", &VISITORCLASS::VisitSVEBitwiseShiftUnpredicated},           \
      {"lsrr_z_p_zz", &VISITORCLASS::VisitSVEBitwiseShiftByVector_Predicated}, \
      {"lsr_z_p_zi", &VISITORCLASS::VisitSVEBitwiseShiftByImm_Predicated},     \
      {"lsr_z_p_zw",                                                           \
       &VISITORCLASS::VisitSVEBitwiseShiftByWideElements_Predicated},          \
      {"lsr_z_p_zz", &VISITORCLASS::VisitSVEBitwiseShiftByVector_Predicated},  \
      {"lsr_z_zi", &VISITORCLASS::VisitSVEBitwiseShiftUnpredicated},           \
      {"lsr_z_zw", &VISITORCLASS::VisitSVEBitwiseShiftUnpredicated},           \
      {"mad_z_p_zzz", &VISITORCLASS::VisitSVEIntMulAddPredicated},             \
      {"mla_z_p_zzz", &VISITORCLASS::VisitSVEIntMulAddPredicated},             \
      {"mls_z_p_zzz", &VISITORCLASS::VisitSVEIntMulAddPredicated},             \
      {"movprfx_z_p_z", &VISITORCLASS::VisitSVEMovprfx},                       \
      {"movprfx_z_z", &VISITORCLASS::VisitSVEConstructivePrefix_Unpredicated}, \
      {"msb_z_p_zzz", &VISITORCLASS::VisitSVEIntMulAddPredicated},             \
      {"mul_z_p_zz", &VISITORCLASS::VisitSVEIntMulVectors_Predicated},         \
      {"mul_z_zi", &VISITORCLASS::VisitSVEIntMulImm_Unpredicated},             \
      {"nands_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},             \
      {"nand_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"neg_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},      \
      {"nors_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"nor_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},               \
      {"not_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},      \
      {"orns_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"orn_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},               \
      {"orrs_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},              \
      {"orr_p_p_pp_z", &VISITORCLASS::VisitSVEPredicateLogical},               \
      {"orr_z_p_zz", &VISITORCLASS::VisitSVEBitwiseLogical_Predicated},        \
      {"orr_z_zi", &VISITORCLASS::VisitSVEBitwiseLogicalWithImm_Unpredicated}, \
      {"orr_z_zz", &VISITORCLASS::VisitSVEBitwiseLogicalUnpredicated},         \
      {"orv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                      \
      {"pfalse_p", &VISITORCLASS::VisitSVEPredicateZero},                      \
      {"pfirst_p_p_p", &VISITORCLASS::VisitSVEPredicateFirstActive},           \
      {"pnext_p_p_p", &VISITORCLASS::VisitSVEPredicateNextActive},             \
      {"prfb_i_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitGatherPrefetch_VectorPlusImm},              \
      {"prfb_i_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitGatherPrefetch_VectorPlusImm},              \
      {"prfb_i_p_bi_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusImm},               \
      {"prfb_i_p_br_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusScalar},            \
      {"prfb_i_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlus64BitScaledOffsets},          \
      {"prfb_i_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlusUnpacked32BitScaledOffsets},  \
      {"prfb_i_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherPrefetch_ScalarPlus32BitScaledOffsets},          \
      {"prfd_i_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitGatherPrefetch_VectorPlusImm},              \
      {"prfd_i_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitGatherPrefetch_VectorPlusImm},              \
      {"prfd_i_p_bi_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusImm},               \
      {"prfd_i_p_br_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusScalar},            \
      {"prfd_i_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlus64BitScaledOffsets},          \
      {"prfd_i_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlusUnpacked32BitScaledOffsets},  \
      {"prfd_i_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherPrefetch_ScalarPlus32BitScaledOffsets},          \
      {"prfh_i_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitGatherPrefetch_VectorPlusImm},              \
      {"prfh_i_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitGatherPrefetch_VectorPlusImm},              \
      {"prfh_i_p_bi_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusImm},               \
      {"prfh_i_p_br_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusScalar},            \
      {"prfh_i_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlus64BitScaledOffsets},          \
      {"prfh_i_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlusUnpacked32BitScaledOffsets},  \
      {"prfh_i_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherPrefetch_ScalarPlus32BitScaledOffsets},          \
      {"prfw_i_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitGatherPrefetch_VectorPlusImm},              \
      {"prfw_i_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitGatherPrefetch_VectorPlusImm},              \
      {"prfw_i_p_bi_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusImm},               \
      {"prfw_i_p_br_s",                                                        \
       &VISITORCLASS::VisitSVEContiguousPrefetch_ScalarPlusScalar},            \
      {"prfw_i_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlus64BitScaledOffsets},          \
      {"prfw_i_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitGatherPrefetch_ScalarPlusUnpacked32BitScaledOffsets},  \
      {"prfw_i_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE32BitGatherPrefetch_ScalarPlus32BitScaledOffsets},          \
      {"ptest_p_p", &VISITORCLASS::VisitSVEPredicateTest},                     \
      {"ptrues_p_s", &VISITORCLASS::VisitSVEPredicateInitialize},              \
      {"ptrue_p_s", &VISITORCLASS::VisitSVEPredicateInitialize},               \
      {"punpkhi_p_p", &VISITORCLASS::VisitSVEUnpackPredicateElements},         \
      {"punpklo_p_p", &VISITORCLASS::VisitSVEUnpackPredicateElements},         \
      {"rbit_z_p_z", &VISITORCLASS::VisitSVEReverseWithinElements},            \
      {"rdffrs_p_p_f",                                                         \
       &VISITORCLASS::VisitSVEPredicateReadFromFFR_Predicated},                \
      {"rdffr_p_f", &VISITORCLASS::VisitSVEPredicateReadFromFFR_Unpredicated}, \
      {"rdffr_p_p_f", &VISITORCLASS::VisitSVEPredicateReadFromFFR_Predicated}, \
      {"rdvl_r_i", &VISITORCLASS::VisitSVEStackFrameSize},                     \
      {"revb_z_z", &VISITORCLASS::VisitSVEReverseWithinElements},              \
      {"revh_z_z", &VISITORCLASS::VisitSVEReverseWithinElements},              \
      {"revw_z_z", &VISITORCLASS::VisitSVEReverseWithinElements},              \
      {"rev_p_p", &VISITORCLASS::VisitSVEReversePredicateElements},            \
      {"rev_z_z", &VISITORCLASS::VisitSVEReverseVectorElements},               \
      {"sabd_z_p_zz", &VISITORCLASS::VisitSVEIntMinMaxDifference_Predicated},  \
      {"saddv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                    \
      {"scvtf_z_p_z_h2fp16", &VISITORCLASS::VisitSVEIntConvertToFP},           \
      {"scvtf_z_p_z_w2d", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"scvtf_z_p_z_w2fp16", &VISITORCLASS::VisitSVEIntConvertToFP},           \
      {"scvtf_z_p_z_w2s", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"scvtf_z_p_z_x2d", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"scvtf_z_p_z_x2fp16", &VISITORCLASS::VisitSVEIntConvertToFP},           \
      {"scvtf_z_p_z_x2s", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"sdivr_z_p_zz", &VISITORCLASS::VisitSVEIntDivideVectors_Predicated},    \
      {"sdiv_z_p_zz", &VISITORCLASS::VisitSVEIntDivideVectors_Predicated},     \
      {"sdot_z_zzz", &VISITORCLASS::VisitSVEIntMulAddUnpredicated},            \
      {"sdot_z_zzzi_d", &VISITORCLASS::VisitSVEMulIndex},                      \
      {"sdot_z_zzzi_s", &VISITORCLASS::VisitSVEMulIndex},                      \
      {"sel_p_p_pp", &VISITORCLASS::VisitSVEPredicateLogical},                 \
      {"sel_z_p_zz", &VISITORCLASS::VisitSVEVectorSelect},                     \
      {"setffr_f", &VISITORCLASS::VisitSVEFFRInitialise},                      \
      {"smaxv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                    \
      {"smax_z_p_zz", &VISITORCLASS::VisitSVEIntMinMaxDifference_Predicated},  \
      {"smax_z_zi", &VISITORCLASS::VisitSVEIntMinMaxImm_Unpredicated},         \
      {"sminv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                    \
      {"smin_z_p_zz", &VISITORCLASS::VisitSVEIntMinMaxDifference_Predicated},  \
      {"smin_z_zi", &VISITORCLASS::VisitSVEIntMinMaxImm_Unpredicated},         \
      {"smulh_z_p_zz", &VISITORCLASS::VisitSVEIntMulVectors_Predicated},       \
      {"splice_z_p_zz_des", &VISITORCLASS::VisitSVEVectorSplice},              \
      {"sqadd_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},   \
      {"sqadd_z_zz", &VISITORCLASS::VisitSVEIntArithmeticUnpredicated},        \
      {"sqdecb_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdecb_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdecd_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdecd_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdecd_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"sqdech_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdech_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdech_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"sqdecp_r_p_r_sx", &VISITORCLASS::VisitSVEIncDecByPredicateCount},      \
      {"sqdecp_r_p_r_x", &VISITORCLASS::VisitSVEIncDecByPredicateCount},       \
      {"sqdecp_z_p_z", &VISITORCLASS::VisitSVEIncDecByPredicateCount},         \
      {"sqdecw_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdecw_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqdecw_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"sqincb_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqincb_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqincd_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqincd_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqincd_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"sqinch_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqinch_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqinch_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"sqincp_r_p_r_sx", &VISITORCLASS::VisitSVEIncDecByPredicateCount},      \
      {"sqincp_r_p_r_x", &VISITORCLASS::VisitSVEIncDecByPredicateCount},       \
      {"sqincp_z_p_z", &VISITORCLASS::VisitSVEIncDecByPredicateCount},         \
      {"sqincw_r_rs_sx",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqincw_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"sqincw_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"sqsub_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},   \
      {"sqsub_z_zz", &VISITORCLASS::VisitSVEIntArithmeticUnpredicated},        \
      {"st1b_z_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitScatterStore_VectorPlusImm},                \
      {"st1b_z_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitScatterStore_VectorPlusImm},                \
      {"st1b_z_p_bi", &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusImm},   \
      {"st1b_z_p_br",                                                          \
       &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusScalar},               \
      {"st1b_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlus64BitUnscaledOffsets},          \
      {"st1b_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitUnscaledOffsets},  \
      {"st1b_z_p_bz_s_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE32BitScatterStore_ScalarPlus32BitUnscaledOffsets},          \
      {"st1d_z_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitScatterStore_VectorPlusImm},                \
      {"st1d_z_p_bi", &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusImm},   \
      {"st1d_z_p_br",                                                          \
       &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusScalar},               \
      {"st1d_z_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::VisitSVE64BitScatterStore_ScalarPlus64BitScaledOffsets}, \
      {"st1d_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlus64BitUnscaledOffsets},          \
      {"st1d_z_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitScaledOffsets},    \
      {"st1d_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitUnscaledOffsets},  \
      {"st1h_z_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitScatterStore_VectorPlusImm},                \
      {"st1h_z_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitScatterStore_VectorPlusImm},                \
      {"st1h_z_p_bi", &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusImm},   \
      {"st1h_z_p_br",                                                          \
       &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusScalar},               \
      {"st1h_z_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::VisitSVE64BitScatterStore_ScalarPlus64BitScaledOffsets}, \
      {"st1h_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlus64BitUnscaledOffsets},          \
      {"st1h_z_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitScaledOffsets},    \
      {"st1h_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitUnscaledOffsets},  \
      {"st1h_z_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::VisitSVE32BitScatterStore_ScalarPlus32BitScaledOffsets}, \
      {"st1h_z_p_bz_s_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE32BitScatterStore_ScalarPlus32BitUnscaledOffsets},          \
      {"st1w_z_p_ai_d",                                                        \
       &VISITORCLASS::VisitSVE64BitScatterStore_VectorPlusImm},                \
      {"st1w_z_p_ai_s",                                                        \
       &VISITORCLASS::VisitSVE32BitScatterStore_VectorPlusImm},                \
      {"st1w_z_p_bi", &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusImm},   \
      {"st1w_z_p_br",                                                          \
       &VISITORCLASS::VisitSVEContiguousStore_ScalarPlusScalar},               \
      {"st1w_z_p_bz_d_64_scaled",                                              \
       &VISITORCLASS::VisitSVE64BitScatterStore_ScalarPlus64BitScaledOffsets}, \
      {"st1w_z_p_bz_d_64_unscaled",                                            \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlus64BitUnscaledOffsets},          \
      {"st1w_z_p_bz_d_x32_scaled",                                             \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitScaledOffsets},    \
      {"st1w_z_p_bz_d_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE64BitScatterStore_ScalarPlusUnpacked32BitUnscaledOffsets},  \
      {"st1w_z_p_bz_s_x32_scaled",                                             \
       &VISITORCLASS::VisitSVE32BitScatterStore_ScalarPlus32BitScaledOffsets}, \
      {"st1w_z_p_bz_s_x32_unscaled",                                           \
       &VISITORCLASS::                                                         \
           VisitSVE32BitScatterStore_ScalarPlus32BitUnscaledOffsets},          \
      {"st2b_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st2b_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st2d_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st2d_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st2h_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st2h_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st2w_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st2w_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st3b_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st3b_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st3d_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st3d_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st3h_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st3h_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st3w_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st3w_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st4b_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st4b_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st4d_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st4d_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st4h_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st4h_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"st4w_z_p_bi_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusImm},          \
      {"st4w_z_p_br_contiguous",                                               \
       &VISITORCLASS::VisitSVEStoreMultipleStructures_ScalarPlusScalar},       \
      {"stnt1b_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusImm},       \
      {"stnt1b_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusScalar},    \
      {"stnt1d_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusImm},       \
      {"stnt1d_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusScalar},    \
      {"stnt1h_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusImm},       \
      {"stnt1h_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusScalar},    \
      {"stnt1w_z_p_bi_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusImm},       \
      {"stnt1w_z_p_br_contiguous",                                             \
       &VISITORCLASS::VisitSVEContiguousNonTemporalStore_ScalarPlusScalar},    \
      {"str_p_bi", &VISITORCLASS::VisitSVEStorePredicateRegister},             \
      {"str_z_bi", &VISITORCLASS::VisitSVEStoreVectorRegister},                \
      {"subr_z_p_zz",                                                          \
       &VISITORCLASS::VisitSVEIntAddSubtractVectors_Predicated},               \
      {"subr_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},    \
      {"sub_z_p_zz", &VISITORCLASS::VisitSVEIntAddSubtractVectors_Predicated}, \
      {"sub_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},     \
      {"sub_z_zz", &VISITORCLASS::VisitSVEIntArithmeticUnpredicated},          \
      {"sunpkhi_z_z", &VISITORCLASS::VisitSVEUnpackVectorElements},            \
      {"sunpklo_z_z", &VISITORCLASS::VisitSVEUnpackVectorElements},            \
      {"sxtb_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"sxth_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"sxtw_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"tbl_z_zz_1", &VISITORCLASS::VisitSVETableLookup},                      \
      {"trn1_p_pp", &VISITORCLASS::VisitSVEPermutePredicateElements},          \
      {"trn1_z_zz", &VISITORCLASS::VisitSVEPermuteVectorInterleaving},         \
      {"trn2_p_pp", &VISITORCLASS::VisitSVEPermutePredicateElements},          \
      {"trn2_z_zz", &VISITORCLASS::VisitSVEPermuteVectorInterleaving},         \
      {"uabd_z_p_zz", &VISITORCLASS::VisitSVEIntMinMaxDifference_Predicated},  \
      {"uaddv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                    \
      {"ucvtf_z_p_z_h2fp16", &VISITORCLASS::VisitSVEIntConvertToFP},           \
      {"ucvtf_z_p_z_w2d", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"ucvtf_z_p_z_w2fp16", &VISITORCLASS::VisitSVEIntConvertToFP},           \
      {"ucvtf_z_p_z_w2s", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"ucvtf_z_p_z_x2d", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"ucvtf_z_p_z_x2fp16", &VISITORCLASS::VisitSVEIntConvertToFP},           \
      {"ucvtf_z_p_z_x2s", &VISITORCLASS::VisitSVEIntConvertToFP},              \
      {"udivr_z_p_zz", &VISITORCLASS::VisitSVEIntDivideVectors_Predicated},    \
      {"udiv_z_p_zz", &VISITORCLASS::VisitSVEIntDivideVectors_Predicated},     \
      {"udot_z_zzz", &VISITORCLASS::VisitSVEIntMulAddUnpredicated},            \
      {"udot_z_zzzi_d", &VISITORCLASS::VisitSVEMulIndex},                      \
      {"udot_z_zzzi_s", &VISITORCLASS::VisitSVEMulIndex},                      \
      {"umaxv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                    \
      {"umax_z_p_zz", &VISITORCLASS::VisitSVEIntMinMaxDifference_Predicated},  \
      {"umax_z_zi", &VISITORCLASS::VisitSVEIntMinMaxImm_Unpredicated},         \
      {"uminv_r_p_z", &VISITORCLASS::VisitSVEIntReduction},                    \
      {"umin_z_p_zz", &VISITORCLASS::VisitSVEIntMinMaxDifference_Predicated},  \
      {"umin_z_zi", &VISITORCLASS::VisitSVEIntMinMaxImm_Unpredicated},         \
      {"umulh_z_p_zz", &VISITORCLASS::VisitSVEIntMulVectors_Predicated},       \
      {"uqadd_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},   \
      {"uqadd_z_zz", &VISITORCLASS::VisitSVEIntArithmeticUnpredicated},        \
      {"uqdecb_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdecb_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdecd_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdecd_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdecd_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"uqdech_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdech_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdech_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"uqdecp_r_p_r_uw", &VISITORCLASS::VisitSVEIncDecByPredicateCount},      \
      {"uqdecp_r_p_r_x", &VISITORCLASS::VisitSVEIncDecByPredicateCount},       \
      {"uqdecp_z_p_z", &VISITORCLASS::VisitSVEIncDecByPredicateCount},         \
      {"uqdecw_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdecw_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqdecw_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"uqincb_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqincb_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqincd_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqincd_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqincd_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"uqinch_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqinch_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqinch_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"uqincp_r_p_r_uw", &VISITORCLASS::VisitSVEIncDecByPredicateCount},      \
      {"uqincp_r_p_r_x", &VISITORCLASS::VisitSVEIncDecByPredicateCount},       \
      {"uqincp_z_p_z", &VISITORCLASS::VisitSVEIncDecByPredicateCount},         \
      {"uqincw_r_rs_uw",                                                       \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqincw_r_rs_x",                                                        \
       &VISITORCLASS::VisitSVESaturatingIncDecRegisterByElementCount},         \
      {"uqincw_z_zs",                                                          \
       &VISITORCLASS::VisitSVESaturatingIncDecVectorByElementCount},           \
      {"uqsub_z_zi", &VISITORCLASS::VisitSVEIntAddSubtractImm_Unpredicated},   \
      {"uqsub_z_zz", &VISITORCLASS::VisitSVEIntArithmeticUnpredicated},        \
      {"uunpkhi_z_z", &VISITORCLASS::VisitSVEUnpackVectorElements},            \
      {"uunpklo_z_z", &VISITORCLASS::VisitSVEUnpackVectorElements},            \
      {"uxtb_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"uxth_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"uxtw_z_p_z", &VISITORCLASS::VisitSVEIntUnaryArithmeticPredicated},     \
      {"uzp1_p_pp", &VISITORCLASS::VisitSVEPermutePredicateElements},          \
      {"uzp1_z_zz", &VISITORCLASS::VisitSVEPermuteVectorInterleaving},         \
      {"uzp2_p_pp", &VISITORCLASS::VisitSVEPermutePredicateElements},          \
      {"uzp2_z_zz", &VISITORCLASS::VisitSVEPermuteVectorInterleaving},         \
      {"whilele_p_p_rr",                                                       \
       &VISITORCLASS::VisitSVEIntCompareScalarCountAndLimit},                  \
      {"whilelo_p_p_rr",                                                       \
       &VISITORCLASS::VisitSVEIntCompareScalarCountAndLimit},                  \
      {"whilels_p_p_rr",                                                       \
       &VISITORCLASS::VisitSVEIntCompareScalarCountAndLimit},                  \
      {"whilelt_p_p_rr",                                                       \
       &VISITORCLASS::VisitSVEIntCompareScalarCountAndLimit},                  \
      {"wrffr_f_p", &VISITORCLASS::VisitSVEFFRWriteFromPredicate},             \
      {"zip1_p_pp", &VISITORCLASS::VisitSVEPermutePredicateElements},          \
      {"zip1_z_zz", &VISITORCLASS::VisitSVEPermuteVectorInterleaving},         \
      {"zip2_p_pp", &VISITORCLASS::VisitSVEPermutePredicateElements}, {        \
    "zip2_z_zz", &VISITORCLASS::VisitSVEPermuteVectorInterleaving              \
  }