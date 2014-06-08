/*
 * Tests for the libxlsxwriter library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include <gtest/gtest.h>
#include "../helper.h"

#include "xlsxwriter/core.h"

// Test _xml_declaration().
TEST(core, xml_declaration) {

    char* got;
    char exp[] = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
    FILE* testfile = tmpfile();

    lxw_core *core = _new_core();
    core->file = testfile;

    _core_xml_declaration(core);

    RUN_XLSX_STREQ(exp, got);

    _free_core(core);
}