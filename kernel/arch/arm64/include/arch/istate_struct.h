/*
 * Copyright (c) 2015 Petr Pavlu
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KERN_ARCH_ISTATE_STRUCT_H_
#define KERN_ARCH_ISTATE_STRUCT_H_

#define ISTATE_OFFSET_SPSR   0x00
#define ISTATE_OFFSET_SP     0x08
#define ISTATE_OFFSET_PC     0x10
#define ISTATE_OFFSET_TPIDR  0x18
#define ISTATE_OFFSET_X0     0x20
#define ISTATE_OFFSET_X1     0x28
#define ISTATE_OFFSET_X2     0x30
#define ISTATE_OFFSET_X3     0x38
#define ISTATE_OFFSET_X4     0x40
#define ISTATE_OFFSET_X5     0x48
#define ISTATE_OFFSET_X6     0x50
#define ISTATE_OFFSET_X7     0x58
#define ISTATE_OFFSET_X8     0x60
#define ISTATE_OFFSET_X9     0x68
#define ISTATE_OFFSET_X10    0x70
#define ISTATE_OFFSET_X11    0x78
#define ISTATE_OFFSET_X12    0x80
#define ISTATE_OFFSET_X13    0x88
#define ISTATE_OFFSET_X14    0x90
#define ISTATE_OFFSET_X15    0x98
#define ISTATE_OFFSET_X16    0xa0
#define ISTATE_OFFSET_X17    0xa8
#define ISTATE_OFFSET_X18    0xb0
#define ISTATE_OFFSET_X19    0xb8
#define ISTATE_OFFSET_X20    0xc0
#define ISTATE_OFFSET_X21    0xc8
#define ISTATE_OFFSET_X22    0xd0
#define ISTATE_OFFSET_X23    0xd8
#define ISTATE_OFFSET_X24    0xe0
#define ISTATE_OFFSET_X25    0xe8
#define ISTATE_OFFSET_X26    0xf0
#define ISTATE_OFFSET_X27    0xf8
#define ISTATE_OFFSET_X28    0x100
#define ISTATE_OFFSET_X29    0x108
#define ISTATE_OFFSET_X30    0x110
#define ISTATE_OFFSET_PAD0   0x118
#define ISTATE_SIZE          0x120

#ifndef __ASSEMBLER__

#include <stdint.h>

typedef struct istate {
	uint64_t spsr;
	uint64_t sp;
	uint64_t pc;
	uint64_t tpidr;
	uint64_t x0;
	uint64_t x1;
	uint64_t x2;
	uint64_t x3;
	uint64_t x4;
	uint64_t x5;
	uint64_t x6;
	uint64_t x7;
	uint64_t x8;
	uint64_t x9;
	uint64_t x10;
	uint64_t x11;
	uint64_t x12;
	uint64_t x13;
	uint64_t x14;
	uint64_t x15;
	uint64_t x16;
	uint64_t x17;
	uint64_t x18;
	uint64_t x19;
	uint64_t x20;
	uint64_t x21;
	uint64_t x22;
	uint64_t x23;
	uint64_t x24;
	uint64_t x25;
	uint64_t x26;
	uint64_t x27;
	uint64_t x28;
	/* Frame Pointer. */
	uint64_t x29;
	/* Link Register. */
	uint64_t x30;

	/*
	 * ARM64 mandates that the stack pointer is always aligned to
	 * a 16-byte boundary. To satisfy this condition, the size of
	 * this data structure needs to be also a multiple of 16 bytes.
	 * This is the reason for this padding.
	 */
	uint64_t pad0;
} istate_t;

#endif

#endif
