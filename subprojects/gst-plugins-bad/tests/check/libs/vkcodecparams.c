/* GStreamer
 *
 * Copyright (C) 2024 Igalia, S.L.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/* H264 DECODER: 1 frame 320x240 blue box  */
static StdVideoH264HrdParameters h264_std_hrd = {
  .cpb_cnt_minus1 = 0,
  .bit_rate_scale = 4,
  .cpb_size_scale = 0,
  .reserved1 = 0,
  .bit_rate_value_minus1 = {2928,},
  .cpb_size_value_minus1 = {74999,},
  .cbr_flag = {0,},
  .initial_cpb_removal_delay_length_minus1 = 23,
  .cpb_removal_delay_length_minus1 = 23,
  .dpb_output_delay_length_minus1 = 23,
  .time_offset_length = 24,
};

static StdVideoH264SequenceParameterSetVui h264_std_vui = {
  .flags = {
        .aspect_ratio_info_present_flag = 1,
        .overscan_info_present_flag = 0,
        .overscan_appropriate_flag = 0,
        .video_signal_type_present_flag = 0,
        .video_full_range_flag = 1,
        .color_description_present_flag = 0,
        .chroma_loc_info_present_flag = 1,
        .timing_info_present_flag = 1,
        .fixed_frame_rate_flag = 1,
        .bitstream_restriction_flag = 1,
        .nal_hrd_parameters_present_flag = 1,
        .vcl_hrd_parameters_present_flag = 0,
      },
  .aspect_ratio_idc = STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE,
  .sar_width = 1,
  .sar_height = 1,
  .video_format = 0,
  .colour_primaries = 0,
  .transfer_characteristics = 0,
  .matrix_coefficients = 2,
  .num_units_in_tick = 1,
  .time_scale = 60,
  .max_num_reorder_frames = 0,
  .max_dec_frame_buffering = 2,
  .chroma_sample_loc_type_top_field = 0,
  .chroma_sample_loc_type_bottom_field = 0,
  .pHrdParameters = &h264_std_hrd,
};

static StdVideoH264SequenceParameterSet h264_std_sps = {
  .flags = {
        .constraint_set0_flag = 0,
        .constraint_set1_flag = 0,
        .constraint_set2_flag = 0,
        .constraint_set3_flag = 0,
        .constraint_set4_flag = 0,
        .constraint_set5_flag = 0,
        .direct_8x8_inference_flag = 1,
        .mb_adaptive_frame_field_flag = 0,
        .frame_mbs_only_flag = 1,
        .delta_pic_order_always_zero_flag = 0,
        .separate_colour_plane_flag = 0,
        .gaps_in_frame_num_value_allowed_flag = 0,
        .qpprime_y_zero_transform_bypass_flag = 0,
        .frame_cropping_flag = 0,
        .seq_scaling_matrix_present_flag = 0,
        .vui_parameters_present_flag = 1,
      },
  .profile_idc = STD_VIDEO_H264_PROFILE_IDC_MAIN,
  .level_idc = STD_VIDEO_H264_LEVEL_IDC_2_1,
  .chroma_format_idc = STD_VIDEO_H264_CHROMA_FORMAT_IDC_420,
  .seq_parameter_set_id = 0,
  .bit_depth_luma_minus8 = 0,
  .bit_depth_chroma_minus8 = 0,
  .log2_max_frame_num_minus4 = 4,
  .pic_order_cnt_type = STD_VIDEO_H264_POC_TYPE_2,
  .offset_for_non_ref_pic = 0,
  .offset_for_top_to_bottom_field = 0,
  .log2_max_pic_order_cnt_lsb_minus4 = 0,
  .num_ref_frames_in_pic_order_cnt_cycle = 0,
  .max_num_ref_frames = 2,
  .pic_width_in_mbs_minus1 = 19,
  .pic_height_in_map_units_minus1 = 14,
  .frame_crop_left_offset = 0,
  .frame_crop_right_offset = 0,
  .frame_crop_top_offset = 0,
  .frame_crop_bottom_offset = 0,
  .pOffsetForRefFrame = NULL,
  .pScalingLists = NULL,
  .pSequenceParameterSetVui = &h264_std_vui,
};

static StdVideoH264PictureParameterSet h264_std_pps = {
  .flags = {
        .transform_8x8_mode_flag = 0,
        .redundant_pic_cnt_present_flag = 0,
        .constrained_intra_pred_flag = 0,
        .deblocking_filter_control_present_flag = 1,
        .weighted_pred_flag = 0,
        .bottom_field_pic_order_in_frame_present_flag = 0,
        .entropy_coding_mode_flag = 1,
        .pic_scaling_matrix_present_flag = 0,
      },
  .seq_parameter_set_id = 0,
  .pic_parameter_set_id = 0,
  .num_ref_idx_l0_default_active_minus1 = 0,
  .num_ref_idx_l1_default_active_minus1 = 0,
  .weighted_bipred_idc = STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT,
  .pic_init_qp_minus26 = 0,
  .pic_init_qs_minus26 = 0,
  .chroma_qp_index_offset = 0,
  .second_chroma_qp_index_offset = 0,
  .pScalingLists = NULL,
};

static const uint8_t h264_slice[] = {
  0x25, 0x88, 0x80, 0x4f, 0xb8, 0x15, 0x59, 0xd0, 0x00, 0x3d, 0xe7, 0xfe, 0x6e,
  0x22, 0xeb, 0xb9, 0x72, 0x7b, 0x52, 0x8d, 0xd8, 0xf7, 0x14, 0x97, 0xc7, 0xa3,
  0x62, 0xb7, 0x6a, 0x61, 0x8e, 0xd2, 0xec, 0x64, 0xbc, 0xa4, 0x00, 0x00, 0x05,
  0x93, 0xa2, 0x39, 0xa9, 0x99, 0x1e, 0xc5, 0x01, 0x4a, 0x00, 0x0c, 0x03, 0x0d,
  0x75, 0x45, 0x2a, 0xe3, 0x3d, 0x7f, 0x10, 0x03, 0x82
};

/* H265 DECODER: 1 frame 320x240 blue box  */
static StdVideoH265HrdParameters h265_std_hrd = { 0, };

static StdVideoH265ProfileTierLevel h265_std_ptl = {
  .flags = {
        .general_progressive_source_flag = 1,
        .general_frame_only_constraint_flag = 1,
      },
  .general_profile_idc = STD_VIDEO_H265_PROFILE_IDC_MAIN,
  .general_level_idc = STD_VIDEO_H265_LEVEL_IDC_6_0,
};

static StdVideoH265DecPicBufMgr h265_std_pbm = {
  .max_latency_increase_plus1 = {5, 0,},
  .max_dec_pic_buffering_minus1 = {4, 0,},
  .max_num_reorder_pics = {2, 0,},
};

static StdVideoH265VideoParameterSet h265_std_vps = {
  .flags = {
        .vps_temporal_id_nesting_flag = 1,
        .vps_sub_layer_ordering_info_present_flag = 1,
      },
  .vps_video_parameter_set_id = 0,
  .pDecPicBufMgr = &h265_std_pbm,
  .pHrdParameters = &h265_std_hrd,
  .pProfileTierLevel = &h265_std_ptl,
};

static StdVideoH265SequenceParameterSetVui h265_std_sps_vui = {
  .flags = {
        .video_signal_type_present_flag = 1,
        .vui_timing_info_present_flag = 1,
      },
  .aspect_ratio_idc = STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED,
  .video_format = 5,
  .colour_primaries = 2,
  .transfer_characteristics = 2,
  .matrix_coeffs = 2,
  .vui_num_units_in_tick = 1,
  .vui_time_scale = 25,
  .pHrdParameters = &h265_std_hrd,
};

static StdVideoH265SequenceParameterSet h265_std_sps = {
  .flags = {
        .sps_temporal_id_nesting_flag = 1,
        .sps_sub_layer_ordering_info_present_flag = 1,
        .sample_adaptive_offset_enabled_flag = 1,
        .sps_temporal_mvp_enabled_flag = 1,
        .strong_intra_smoothing_enabled_flag = 1,
        .vui_parameters_present_flag = 1,
        .sps_extension_present_flag = 1,
      },
  .chroma_format_idc = STD_VIDEO_H265_CHROMA_FORMAT_IDC_420,
  .pic_width_in_luma_samples = 320,
  .pic_height_in_luma_samples = 240,
  .sps_video_parameter_set_id = 0,
  .sps_seq_parameter_set_id = 0,
  .log2_max_pic_order_cnt_lsb_minus4 = 4,
  .log2_diff_max_min_luma_coding_block_size = 3,
  .log2_diff_max_min_luma_transform_block_size = 3,
  .pProfileTierLevel = &h265_std_ptl,
  .pDecPicBufMgr = &h265_std_pbm,
  .pSequenceParameterSetVui = &h265_std_sps_vui,
};

static StdVideoH265PictureParameterSet h265_std_pps = {
  .flags = {
        .sign_data_hiding_enabled_flag = 1,
        .cu_qp_delta_enabled_flag = 1,
        .weighted_pred_flag = 1,
        .entropy_coding_sync_enabled_flag = 1,
        .uniform_spacing_flag = 1,
        .loop_filter_across_tiles_enabled_flag = 1,
        .pps_loop_filter_across_slices_enabled_flag = 1,
      },
  .pps_pic_parameter_set_id = 0,
  .pps_seq_parameter_set_id = 0,
  .sps_video_parameter_set_id = 0,
  .diff_cu_qp_delta_depth = 1,
};

static const uint8_t h265_slice[] = {
  0x28, 0x01, 0xaf, 0x1d, 0x21, 0x6a, 0x83, 0x40, 0xf7, 0xcf, 0x80, 0xff, 0xf8,
  0x90, 0xfa, 0x3b, 0x77, 0x87, 0x96, 0x96, 0xba, 0xfa, 0xcd, 0x61, 0xb5, 0xe3,
  0xc1, 0x02, 0x2d, 0xe0, 0xa8, 0x17, 0x96, 0x03, 0x4c, 0x4e, 0x1a, 0x9e, 0xd0,
  0x93, 0x0b, 0x93, 0x40, 0x00, 0x05, 0xec, 0x87, 0x00, 0x00, 0x03, 0x00, 0x00,
  0x03, 0x00, 0x56, 0x40
};
