/*
 * Copyright (c) 2019-2021, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cudf/column/column_view.hpp>

/**
 * @file
 * @brief Class definition for cudf::strings_column_view
 */

namespace cudf {

/**
 * @addtogroup strings_classes
 * @{
 */

/**
 * @brief Given a column-view of strings type, an instance of this class
 * provides a wrapper on this compound column for strings operations.
 */
class strings_column_view : private column_view {
 public:
  strings_column_view(column_view strings_column);
  strings_column_view(strings_column_view&& strings_view)      = default;
  strings_column_view(const strings_column_view& strings_view) = default;
  ~strings_column_view()                                       = default;
  strings_column_view& operator=(strings_column_view const&) = default;
  strings_column_view& operator=(strings_column_view&&) = default;

  static constexpr size_type offsets_column_index{0};
  static constexpr size_type chars_column_index{1};

  using column_view::has_nulls;
  using column_view::is_empty;
  using column_view::null_count;
  using column_view::null_mask;
  using column_view::offset;
  using column_view::size;

  using offset_iterator = offset_type const*;
  using chars_iterator  = char const*;

  /**
   * @brief Returns the parent column.
   */
  [[nodiscard]] column_view parent() const;

  /**
   * @brief Returns the internal column of offsets
   *
   * @throw cudf::logic error if this is an empty column
   */
  [[nodiscard]] column_view offsets() const;

  /**
   * @brief Return an iterator for the offsets child column.
   *
   * This automatically applies the offset of the parent.
   *
   * @return Iterator pointing to the first offset value.
   */
  [[nodiscard]] offset_iterator offsets_begin() const;

  /**
   * @brief Return an end iterator for the offsets child column.
   *
   * This automatically applies the offset of the parent.
   *
   * @return Iterator pointing 1 past the last offset value.
   */
  [[nodiscard]] offset_iterator offsets_end() const;

  /**
   * @brief Returns the internal column of chars
   *
   * @throw cudf::logic error if this is an empty column
   */
  [[nodiscard]] column_view chars() const;

  /**
   * @brief Returns the number of bytes in the chars child column.
   *
   * This accounts for empty columns but does not reflect a sliced parent column
   * view  (i.e.: non-zero offset or reduced row count).
   */
  [[nodiscard]] size_type chars_size() const noexcept;

  /**
   * @brief Return an iterator for the chars child column.
   *
   * This does not apply the offset of the parent.
   * The offsets child must be used to properly address the char bytes.
   *
   * For example, to access the first character of string `i` (accounting for
   * a sliced column offset) use: `chars_begin()[offsets_begin()[i]]`.
   *
   * @return Iterator pointing to the first char byte.
   */
  [[nodiscard]] chars_iterator chars_begin() const;

  /**
   * @brief Return an end iterator for the offsets child column.
   *
   * This does not apply the offset of the parent.
   * The offsets child must be used to properly address the char bytes.
   *
   * @return Iterator pointing 1 past the last char byte.
   */
  [[nodiscard]] chars_iterator chars_end() const;
};

//! Strings column APIs.
namespace strings {
}  // namespace strings

/** @} */  // end of group
}  // namespace cudf
