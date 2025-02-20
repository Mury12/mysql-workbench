/*
 * Copyright (c) 2017, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is designed to work with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms, as
 * designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have either included with
 * the program or referenced in the documentation.
 * This program is distributed in the hope that it will be useful,  but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 * the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 
 */

#pragma once

#include "events.h"
#include "common.h"

namespace mga {

  class ScriptingContext;

  // Partial implementation of the Node.js Process class.
  class Process : public EventEmitter {
  public:
    static ExitCode exitCode;
    static bool waitBeforeExit; // Mostly useful on Windows when running from Visual Studio.

    // Must be called from main() to store arguments + env values.
    static void initialize(int argc, const char* argv[], char* envp[]);

    static void chdir(std::string const& path);
    static std::string cwd();
    static std::map<std::string, std::string> env();
    static void exit(ExitCode code = exitCode);
    static void onExit(ScriptingContext &context);

    static void activate(ScriptingContext &context, JSObject &exports);

    static bool _registered;
  };

} // namespace mga
