/*  Wayfire Plugin to Minimize Windows
 *  Copyright (C) 2020 masm11
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <wayfire/plugin.hpp>
#include <wayfire/output.hpp>
#include <wayfire/core.hpp>
#include <wayfire/view.hpp>
#include <wayfire/util/duration.hpp>
#include <wayfire/workspace-manager.hpp>
#include <wayfire/render-manager.hpp>
#include <wayfire/compositor-view.hpp>
#include <wayfire/output-layout.hpp>
#include <wayfire/debug.hpp>

#include <cmath>
#include <linux/input.h>
#include <wayfire/signal-definitions.hpp>

class wayfire_minimize : public wf::plugin_interface_t
{
    wf::key_callback activate_binding;
    // wayfire_view view;

    wf::option_wrapper_t<wf::keybinding_t> activate_key{"minimize/activate"};

    public:
        void init() override
        {
            grab_interface->name = "minimize";
            grab_interface->capabilities = wf::CAPABILITY_MANAGE_DESKTOP;

            activate_binding = [=] (uint32_t)
            {
                auto view = wf::get_core().get_cursor_focus_view();

		if (view && view->role == wf::VIEW_ROLE_TOPLEVEL && view->is_mapped())
		    view->minimize_request(true);

                return true;
            };

            output->add_key(activate_key, &activate_binding);
        }

        void fini() override
        {
            output->rem_binding(&activate_binding);
        }
};

DECLARE_WAYFIRE_PLUGIN(wayfire_minimize);
