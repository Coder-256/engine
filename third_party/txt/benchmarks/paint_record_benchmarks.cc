/*
 * Copyright 2017 Google, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "third_party/benchmark/include/benchmark/benchmark_api.h"

#include "lib/fxl/command_line.h"
#include "lib/fxl/logging.h"
#include "txt/paint_record.h"
#include "txt/text_style.h"
#include "utils.h"

namespace txt {

static void BM_PaintRecordInit(benchmark::State& state) {
  TextStyle style;

  SkPaint paint;
  paint.setAntiAlias(true);
  paint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);
  paint.setTextSize(14);
  paint.setFakeBoldText(false);

  SkTextBlobBuilder builder;
  builder.allocRunPos(paint, 100);
  auto text_blob = builder.make();

  while (state.KeepRunning()) {
    PaintRecord PaintRecord(style, text_blob, SkPaint::FontMetrics(), 0, 0);
  }
}
BENCHMARK(BM_PaintRecordInit);

}  // namespace txt
