/* Copyright 2017 Gabriel Rauter <rauter.gabriel@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CARRERA_H
#define CARRERA_H

#include "quantum.h"

// The first section contains all of the arguments (phisical keys representation)
// The second converts the arguments into a two-dimensional array (keyboard matrix)
#define KEYMAP( \
      k48, k01, k04, k08, k12, k16, k20, k24, k28, k32, k36, k40, k44, k54, k55,                  \
      k49,   k02, k06, k10, k14, k18, k22, k26, k30, k34, k38, k42, k45,    k56,    kS4_1, kS4_2, \
      k50,    k03, k07, k11, k15, k19, k23, k27, k31, k35, k39, k43, k46,   k53,             kS3, \
      k51,     k05, k09, k13, k17, k21, k25, k29, k33, k37, k41,/*k52 = k51,*/      kS2_1, kS2_2, \
      k62,  k57,  k58,                  k59,                k60,  k61,                       kS1  \
) \
{ \
    { k13, k09, k48, k59, k25, k37, k53, k51, KC_NO }, \
    { k16, k12, k49, k28, k29, k44, k54, KC_NO, kS3 }, \
    { k15, k11, k01, k27, k30, k43, k60, KC_NO, kS2_2 }, \
    { k14, k10, k04, k26, k31, k42, k45, KC_NO, kS2_1 }, \
    { k17, k08, k05, k21, k36, k40, k46, k56, kS4_1 }, \
    { k19, k06, k03, k23, k35, k33, k61, KC_NO, kS1 }, \
    { k20, k58, k57, k24, k32, k38, k55, k62, kS4_2 }, \
    { k18, k07, k02, k22, k34, k39, k41, k50, KC_NO }, \
}

#endif
