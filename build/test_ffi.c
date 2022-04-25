
#define LUA_LIB

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <memory.h>
#include <stdlib.h>


typedef struct Vector3 {
    float x, y, z;
} Vector3;

typedef struct VectorHandle {
    Vector3* vector3;
    int len;
} VectorHandle;

LUA_API VectorHandle* test_ffi_init() {
    VectorHandle* handle = (VectorHandle*)malloc(sizeof(VectorHandle));
    memset(handle, 0, sizeof(VectorHandle));
    return handle;
}

LUA_API Vector3* test_ffi_create(VectorHandle* handle, int size) {
    if (handle && size) {
        if (handle->vector3 != NULL) {
            if (handle->len != size) {
                free(handle->vector3);
            }
        }
        if (handle->vector3 == NULL) {
            handle->vector3 = malloc(sizeof(Vector3) * size);
            handle->len = size;
        }
    }
    return handle ? handle->vector3 : NULL;
}

LUA_API void test_ffi_close(VectorHandle* handle) {
    if (handle) {
        if (handle->vector3) {
            free(handle->vector3);
        }
        free(handle);
    }
}
