//
// Created by Angus Goucher on 10/13/2024.
//

#include "Log.h"

#include <stdio.h>

void H2O::Log::Info(const H2O::String& Text) {
    printf("INFO: %s\n", Text.Data);
}

void H2O::Log::Warning(const H2O::String& Text) {
    printf("WARN: %s\n", Text.Data);
}

void H2O::Log::Error(const H2O::String& Text) {
    printf("ERROR: %s\n", Text.Data);
}
