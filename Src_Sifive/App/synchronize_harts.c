/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

/*
 * _synchronize_harts() is called by crt0.S to cause harts > 0 to wait for
 * hart 0 to finish copying the datat section, zeroing the BSS, and running
 * the libc contstructors.
 */
__attribute__((section(".init"))) void __metal_synchronize_harts()
{
	
}
