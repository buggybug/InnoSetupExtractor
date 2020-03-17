//+---------------------------------------------------------------------------
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
//     dllmain.cpp
//
// Abstract:
//
//     This module contains the implementation of the DLL entry point and its
//     exported functions for providing COM support.
//
//     None of this functions are supposed to be called directly. Use the
//     Win32 and/or COM routines instead.
//
//----------------------------------------------------------------------------

#include "pch.h"
#include <OleCtl.h>
#include <wrl\module.h>

/// <summary>
///     An entry point into a dynamic-link library (DLL).
/// </summary>
/// <param name="hinst">
///     A handle to the DLL module. The value is the base address of the DLL.
/// </param>
/// <param name="reason">
///     The reason code that indicates why the DLL entry-point function is
///     being called.
/// </param>
/// <param name="context">
///     (unused argument) if <paramref name="reason"/> is DLL_PROCESS_ATTACH,
///     <paramref name="context"/> is NULL for dynamic loads and non-NULL for
///     static loads.
/// </param>
/// <returns>
///     When the system calls the DllMain function with the DLL_PROCESS_ATTACH
///     value, the function returns TRUE if it succeeds or FALSE if
///     initialization fails.
///
///     When the system calls the DllMain function with any value other than
///     DLL_PROCESS_ATTACH, the return value is ignored.
/// </returns>
/// <remarks>
///     When the system starts or terminates a process or thread, it calls the
///     entry-point function for each loaded DLL using the first thread of the
///     process. The system also calls the entry-point function for a DLL when
///     it is loaded or unloaded using the LoadLibrary and FreeLibrary
///     functions.
/// </remarks>
/**/
STDAPI_(BOOL) DllMain(_In_ HINSTANCE hinst, DWORD reason, _In_opt_ void* context) noexcept
{
#if defined(_DLL)
    // Disable the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notification
    // calls as the DLL does not provide any handlers for thread-level
    // attachment/detachment notifications. This can be a useful
    // optimization for multithreaded applications that frequently create
    // and delete threads
    //
    // Only DLLs that are linked to the dynamic C run-time library (CRT)
    // may implement the optimization
    if (DLL_PROCESS_ATTACH == reason)
    {
        ::DisableThreadLibraryCalls(hinst);
    }
#endif // defined(_DLL)
    UNREFERENCED_PARAMETER(hinst);
    UNREFERENCED_PARAMETER(reason);
    UNREFERENCED_PARAMETER(context);

    return TRUE;
}

/// <summary>
///     Used to determine whether the DLL can be unloaded by OLE.
/// </summary>
/// <returns>
///     S_OK - DLL can be unloaded.
///     S_FALSE - DLL cannot be unloaded now.
/// </returns>
/**/
_Use_decl_annotations_ STDAPI DllCanUnloadNow() noexcept
{
    return Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule().Terminate() ? S_OK : S_FALSE;
}

/// <summary>
///     Returns a class factory to create an object of the requested type.
/// </summary>
/// <param name="rclsid">
///     The CLSID that will associate the correct data and code.
/// </param>
/// <param name="riid">
///     A reference to the identifier of the interface that the caller is to
///     use to communicate with the class object.
/// </param>
/// <param name="ppv">
///     The address of a pointer variable that receives the interface pointer
///     requested in <paramref name="riid"/>. Upon successful return,
///     <paramref name="ppv"/> contains the requested interface pointer. If an
///     error occurs, the interface pointer is NULL.
/// </param>
/// <returns>
///     Various HRESULT codes.
///
///     S_OK - The object was retrieved successfully.
///     CLASS_E_CLASSNOTAVAILABLE - The DLL does not support the class.
/// </returns>
/**/
_Use_decl_annotations_ STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID FAR* ppv) noexcept
{
#if !defined(__WRL_WINRT_STRICT__)
    return Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule().GetClassObject(rclsid, riid, ppv);
#else // defined(__WRL_WINRT_STRICT__)
    UNREFERENCED_PARAMETER(rclsid);
    UNREFERENCED_PARAMETER(riid);
    UNREFERENCED_PARAMETER(ppv);
#if (NTDDI_VERSION >= NTDDI_WINBLUE)
    ::RoOriginateError(E_NOTIMPL, nullptr);
#endif // (NTDDI_VERSION >= NTDDI_WINBLUE)
    return E_NOTIMPL;
#endif // !defined(__WRL_WINRT_STRICT__)
}

/// <summary>
///     Adds entries to the system registry for all classes supported in this
///     server module.
/// </summary>
/// <returns>
///     Various HRESULT codes.
///
///     S_OK - The registry entries were created successfully.
///     SELFREG_E_TYPELIB - The server was unable to complete the registration
///                         of all the type libraries used by its classes.
///     SELFREG_E_CLASS - The server was unable to complete the registration
///                       of all the object classes.
/// </returns>
/**/
_Use_decl_annotations_ STDAPI DllRegisterServer() noexcept
{
#if !defined(__WRL_WINRT_STRICT__)
    return E_NOTIMPL;
#else // defined(__WRL_WINRT_STRICT__)
#if (NTDDI_VERSION >= NTDDI_WINBLUE)
    ::RoOriginateError(E_NOTIMPL, nullptr);
#endif // (NTDDI_VERSION >= NTDDI_WINBLUE)
    return E_NOTIMPL;
#endif // !defined(__WRL_WINRT_STRICT__)
}

/// <summary>
///     Removes entries from the system registry created through the
///     <seealso cref="DllRegisterServer"/>.
/// </summary>
/// <returns>
///     Various HRESULT codes.
///
///     S_OK - The registry entries were deleted successfully.
///     S_FALSE - Unregistration of this server's known entries was
///               successful, but other entries still exist for this server's
///               classes.
///     SELFREG_E_TYPELIB - The server was unable to remove the entries of all
///                         the type libraries used by its classes.
///     SELFREG_E_CLASS - The server was unable to remove the entries of all
///                       the object classes.
/// </returns>
/**/
_Use_decl_annotations_ STDAPI DllUnregisterServer() noexcept
{
#if !defined(__WRL_WINRT_STRICT__)
    return E_NOTIMPL;
#else // defined(__WRL_WINRT_STRICT__)
#if (NTDDI_VERSION >= NTDDI_WINBLUE)
    ::RoOriginateError(E_NOTIMPL, nullptr);
#endif // (NTDDI_VERSION >= NTDDI_WINBLUE)
    return E_NOTIMPL;
#endif // !defined(__WRL_WINRT_STRICT__)
}

/// <summary>
///     Retrieves the activation factory from a DLL that contains activatable
///     Windows Runtime classes.
/// </summary>
/// <param name="activatibleClassId">
///     The class identifier that is associated with an activatable
///     runtime class.
/// </param>
/// <param name="factory">
///     A pointer to the activation factory that corresponds with the class
///     specified by <paramref name="activatibleClassId"/>.
/// </param>
/// <returns>
///     Various HRESULT codes.
/// </returns>
/**/
STDAPI DllGetActivationFactory(_In_ HSTRING activatibleClassId, __RPC__deref_out IActivationFactory** factory) noexcept
{
#if !defined(__WRL_CLASSIC_COM__)
    return Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule().GetActivationFactory(activatibleClassId, factory);
#else // defined(__WRL_CLASSIC_COM__)
    UNREFERENCED_PARAMETER(activatibleClassId);
    UNREFERENCED_PARAMETER(factory);
#if (NTDDI_VERSION >= NTDDI_WINBLUE)
    ::RoOriginateError(E_NOTIMPL, nullptr);
#endif // (NTDDI_VERSION >= NTDDI_WINBLUE)
    return E_NOTIMPL;
#endif // !defined(__WRL_CLASSIC_COM__)
}
