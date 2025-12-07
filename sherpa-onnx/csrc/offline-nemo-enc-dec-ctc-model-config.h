// sherpa-onnx/csrc/offline-nemo-enc-dec-ctc-model-config.h
//
// Copyright (c)  2023  Xiaomi Corporation
#ifndef SHERPA_ONNX_CSRC_OFFLINE_NEMO_ENC_DEC_CTC_MODEL_CONFIG_H_
#define SHERPA_ONNX_CSRC_OFFLINE_NEMO_ENC_DEC_CTC_MODEL_CONFIG_H_

#include <string>

#include "sherpa-onnx/csrc/parse-options.h"

namespace sherpa_onnx {

struct OfflineNemoEncDecCtcModelConfig {
  std::string model;
  /// if model_buf is non-empty,
  /// the model will be loaded from the buffer instead of from the
  /// "model" file
  std::string model_buf;

  OfflineNemoEncDecCtcModelConfig() = default;
  explicit OfflineNemoEncDecCtcModelConfig(const std::string &model)
      : model(model) {}

  void Register(ParseOptions *po);
  bool Validate() const;

  std::string ToString() const;
};

}  // namespace sherpa_onnx

#endif  // SHERPA_ONNX_CSRC_OFFLINE_NEMO_ENC_DEC_CTC_MODEL_CONFIG_H_
