#pragma once

#define va_list char *
#define va_start(ap, arg) ((ap) = (va_list)&(arg) + sizeof(arg))
#define va_arg(ap, type) (*((type) *)(((ap) += sizeof(type)) - sizeof(type)))
#define va_end(ap) ((ap) = (va_list)0)
