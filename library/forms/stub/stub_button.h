/*
 * Copyright (c) 2008, 2018, Oracle and/or its affiliates. All rights reserved.
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

#ifndef _STUB_BUTTON_H_
#define _STUB_BUTTON_H_

#include "stub_view.h"

namespace mforms {
  namespace stub {

    class ButtonWrapper : public ViewWrapper {
    protected:
      ButtonWrapper(::mforms::Button *self, bool concrete = false) : ViewWrapper(self) {
      }

      static void callback(::mforms::Button *self) {
      }

      static bool create(::mforms::Button *self, ::mforms::ButtonType) {
        return true;
      }

      static void set_text(::mforms::Button *self, const std::string &text) {
      }

      static void enable_internal_padding(Button *self, bool enabled) {
      }

      static void set_icon(Button *self, const std::string &path) {
      }

    public:
      static void init() {
        ::mforms::ControlFactory *f = ::mforms::ControlFactory::get_instance();

        f->_button_impl.create = &ButtonWrapper::create;
        f->_button_impl.set_text = &ButtonWrapper::set_text;
        f->_button_impl.set_icon = &ButtonWrapper::set_icon;
        f->_button_impl.enable_internal_padding = &ButtonWrapper::enable_internal_padding;
      }
    };
  }
}

#endif
