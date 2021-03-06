// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "open3d/core/linalg/Inverse.h"
#include "open3d/core/linalg/LAPACK.h"
#include "open3d/core/linalg/LinalgUtils.h"

namespace open3d {
namespace core {

void InverseCPU(void* A_data,
                void* ipiv_data,
                void* output_data,
                int64_t n,
                Dtype dtype,
                const Device& device) {
    DISPATCH_LINALG_DTYPE_TO_TEMPLATE(dtype, [&]() {
        OPEN3D_LAPACK_CHECK(
                getrf_cpu<scalar_t>(LAPACK_COL_MAJOR, n, n,
                                    static_cast<scalar_t*>(A_data), n,
                                    static_cast<MKL_INT*>(ipiv_data)),
                "getrf failed in InverseCPU");
        OPEN3D_LAPACK_CHECK(
                getri_cpu<scalar_t>(LAPACK_COL_MAJOR, n,
                                    static_cast<scalar_t*>(A_data), n,
                                    static_cast<MKL_INT*>(ipiv_data)),
                "getri failed in InverseCPU");
    });
}

}  // namespace core
}  // namespace open3d
