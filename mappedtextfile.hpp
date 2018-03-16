// Copyright 2017 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MAPPEDTEXTFILE
#define MAPPEDTEXTFILE

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

// A class to allow convenient zero-copy parsing of large text files.
class MappedTextFile {
public:
  MappedTextFile(const std::string& inputfile, const char separator=' ');
  bool GetToken(const char** begin, const char** end) const;
  std::string GetToken() const;
  bool AdvanceLine();
  bool AdvanceToken();
  bool Reset();
private:
  void updateLineEnd();
  void updateTokenEnd();
  boost::interprocess::file_mapping inputfile_;
  boost::interprocess::mapped_region region_;
  const char separator_;
  const char* data_buffer_;
  const char* data_end_;
  const char* current_line_start_;
  const char* current_line_end_;
  const char* current_token_;
  const char* current_token_end_;
};

#endif // MAPPEDTEXTFILE


