/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */
#include "paddle/phi/kernels/funcs/eigen/eigen_function.h"

namespace phi::funcs {

template <typename T, int Rank>
struct EigenConstant<Eigen::DefaultDevice, T, Rank> {
  using Type = Eigen::TensorMap<
      Eigen::Tensor<T, Rank, Eigen::RowMajor, Eigen::DenseIndex>>;
  static void Eval(const Eigen::DefaultDevice& dev, Type out, const T value) {
    out.device(dev) = out.constant(value);
  }
};

template struct EigenConstant<Eigen::DefaultDevice, float, 1>;

}  // namespace phi::funcs
