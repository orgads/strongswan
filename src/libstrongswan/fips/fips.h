/**
 * @file fips.h
 * 
 * @brief Interface of the libstrongswan integrity test
 *
 * @ingroup fips
 */

/*
 * Copyright (C) 2007 Bruno Krieg, Daniel Wydler
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#ifndef FIPS_H_
#define FIPS_H_

#include <library.h>

/**
 * @brief compute SHA-1 HMAC signature over RODATA and TEXT sections of libstrongswan
 *
 * @param  key		key used for SHA-1 HMAC signature in string format
 * @return 		SHA-1 HMAC signature in HEX format
 */
char* fips_compute_hmac_signature(const char *key);

/**
 * @brief verify HMAC signature over RODATA and TEXT sections of libstrongswan
 *
 * @param  signature	signature value from fips_hmac.h in HEX format
 * @param  key		key used for SHA-1 HMAC signature in string format
 * @return		SUCCESS if signatures agree
 */
status_t fips_verify_hmac_signature(const char *signature, const char *key);

#endif /*FIPS_H_*/
