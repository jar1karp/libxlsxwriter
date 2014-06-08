/*
 * Tests for the lib_xlsx_writer library.
 *
 * Copyright 2014, John McNamara, jmcnamara@cpan.org
 *
 */

#include <gtest/gtest.h>
#include "../helper.h"

#include "xlsxwriter/workbook.h"

// Test the _write_workbook_view() function.
TEST(workbook, write_workbook_view1) {


    char* got;
    char exp[] = "<workbookView xWindow=\"240\" yWindow=\"15\" windowWidth=\"16095\" windowHeight=\"9660\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;

    _write_workbook_view(workbook);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

// Test the _write_workbook_view() function.
TEST(workbook, write_workbook_view2) {


    char* got;
    char exp[] = "<workbookView xWindow=\"240\" yWindow=\"15\" windowWidth=\"16095\" windowHeight=\"9660\" activeTab=\"1\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;
    workbook->active_tab = 1;

    _write_workbook_view(workbook);


    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}

// Test the _write_workbook_view() function.
TEST(workbook, write_workbook_view3) {


    char* got;
    char exp[] = "<workbookView xWindow=\"240\" yWindow=\"15\" windowWidth=\"16095\" windowHeight=\"9660\" firstSheet=\"2\" activeTab=\"1\"/>";
    FILE* testfile = tmpfile();

    lxw_workbook *workbook = new_workbook(NULL);
    workbook->file = testfile;
    workbook->active_tab = 1;
    workbook->first_sheet = 2;

    _write_workbook_view(workbook);

    RUN_XLSX_STREQ(exp, got);

    _free_workbook(workbook);
}
