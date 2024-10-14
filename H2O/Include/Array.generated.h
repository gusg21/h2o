//
// Created by Angus Goucher on 10/14/2024.
//

#pragma once

#include "Class.h"

static H2O::Class* MyClass = new H2O::Class("Array");

template <typename ItemType>
H2O::Class* H2O::Array<ItemType>::GetClass() {

}
