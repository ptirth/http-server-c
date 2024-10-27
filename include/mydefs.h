/*
 * http-server-c: A simple HTTP server written in C
 * Copyright (C) 2024  Tirth Patel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;

typedef float f32;
typedef double f64;

#define U8_MAX 255

#define I8_MIN -128
#define I8_MAX 127

#define U16_MAX 65_536

#define I16_MIN -32_768
#define I16_MAX 32_767

#define U32_MAX 4_294_967_296

#define I32_MIN -2_147_483_648
#define I32_MAX 2_147_483_647

#define U64_MAX 18_446_744_073_709_551_615

#define I64_MIN -2_305_843_009_213_693_952
#define I64_MAX 2_305_843_009_213_693_951
