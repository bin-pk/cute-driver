//
// Created by 박경빈 on 25. 1. 30.
//
#pragma once

#define LAST_VERSION 00001

#ifdef WIN
#elif POW
#ifdef TK
#undef LAST_VERSION
#define LAST_VERSION 00002
#endif
#elif DAW
#endif
