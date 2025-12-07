// sherpa-onnx/csrc/offline-nemo-enc-dec-ctc-model-config.cc
//
// Copyright (c)  2023  Xiaomi Corporation

#include "sherpa-onnx/csrc/offline-nemo-enc-dec-ctc-model-config.h"

#include <string>

#include "sherpa-onnx/csrc/file-utils.h"
#include "sherpa-onnx/csrc/macros.h"

namespace sherpa_onnx {

void OfflineNemoEncDecCtcModelConfig::Register(ParseOptions *po) {
  po->Register("nemo-ctc-model", &model,
               "Path to model.onnx of Nemo EncDecCtcModel.");
}

bool OfflineNemoEncDecCtcModelConfig::Validate() const {
  // If model_buf is provided, no need to check file
  if (!model_buf.empty()) {
    return true;
  }

  if (!FileExists(model)) {
    SHERPA_ONNX_LOGE("NeMo model: '%s' does not exist", model.c_str());
    return false;
  }

  return true;
}

std::string OfflineNemoEncDecCtcModelConfig::ToString() const {
  std::ostringstream os;

  os << "OfflineNemoEncDecCtcModelConfig(";
  os << "model=\"" << model << "\")";

  return os.str();
}

}  // namespace sherpa_onnx
