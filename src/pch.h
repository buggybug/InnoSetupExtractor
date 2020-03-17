﻿//+---------------------------------------------------------------------------
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Copyright (c) 2020 Bohdan Yevtukh. All rights reserved.
//
// Module Name:
//
//     pch.h
//
// Abstract:
//
//     Include file for standard system include files, or project specific
//     include files that are used frequently, but are changed infrequently.
//
//----------------------------------------------------------------------------

#if !defined(PCH_H__379C4FA9_AAED_440D_81DF_ECA8E2962828__INCLUDED_)
#define PCH_H__379C4FA9_AAED_440D_81DF_ECA8E2962828__INCLUDED_

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER > 1000)

#include "targetver.h"

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif // !defined(WIN32_LEAN_AND_MEAN)

#include <Windows.h>

// Macro letting the compiler know this is not a kernel driver
// (this will help surpress needless warnings)
__user_driver

#endif // !defined(PCH_H__379C4FA9_AAED_440D_81DF_ECA8E2962828__INCLUDED_)
