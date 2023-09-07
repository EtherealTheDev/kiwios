/*
 * kiwios - An OS made in C that's as simple as eating a kiwi
 * Copyright (C) 2023 kiwiorg
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef SHELL_H
#define SHELL_H

#include "../i386/ps2.h"
#include "../utils/string.h"
#include "../terminal.h"
#include "commands/help.h"

static void shell_run() {
    term_print("$ ", 0x0F);
    char* input = kbd_getstring();

    for(int i = 0; input[i]; i++) input[i] = lower(input[i]); // Convert input to lowercase

    if (!strcmp(input, ""));
    else if (!strcmp(input, "help")) cmd_help();
    else {
        term_print("Command \"", 0x0C);
        term_print(input, 0x0C);
        term_println("\" not found.", 0x0C);
    }
}

#endif
