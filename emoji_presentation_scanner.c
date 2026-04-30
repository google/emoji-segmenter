
#line 1 "emoji_presentation_scanner.rl"
/* Copyright 2019 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdbool.h>

#ifndef EMOJI_LINKAGE
#define EMOJI_LINKAGE static
#endif


#line 26 "emoji_presentation_scanner.c"
static const unsigned char _emoji_presentation_trans_keys[] = {
	0u, 14u, 15u, 16u, 0u, 14u, 10u, 13u, 11u, 13u, 11u, 11u, 5u, 13u, 5u, 13u, 
	7u, 7u, 9u, 13u, 9u, 9u, 9u, 11u, 10u, 15u, 0
};

static const char _emoji_presentation_key_spans[] = {
	15, 2, 15, 4, 3, 1, 9, 9, 
	1, 5, 1, 3, 6
};

static const char _emoji_presentation_index_offsets[] = {
	0, 16, 19, 35, 40, 44, 46, 56, 
	66, 68, 74, 76, 80
};

static const char _emoji_presentation_indicies[] = {
	1, 1, 1, 2, 2, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 1, 0, 
	4, 5, 3, 6, 6, 7, 8, 9, 
	5, 10, 11, 12, 10, 10, 10, 10, 
	10, 13, 10, 5, 14, 15, 16, 0, 
	14, 17, 18, 17, 14, 0, 18, 17, 
	17, 17, 17, 17, 14, 17, 18, 17, 
	18, 0, 0, 0, 0, 5, 14, 15, 
	16, 0, 5, 17, 20, 5, 14, 21, 
	22, 19, 15, 23, 25, 24, 14, 24, 
	5, 14, 15, 16, 17, 4, 17, 0
};

static const char _emoji_presentation_trans_targs[] = {
	2, 4, 6, 2, 1, 2, 3, 3, 
	7, 7, 2, 8, 9, 12, 0, 2, 
	5, 2, 5, 2, 2, 10, 11, 2, 
	2, 2
};

static const char _emoji_presentation_trans_actions[] = {
	1, 2, 2, 3, 0, 4, 7, 2, 
	7, 2, 8, 0, 7, 2, 0, 9, 
	10, 11, 2, 12, 13, 0, 10, 14, 
	15, 16
};

static const char _emoji_presentation_to_state_actions[] = {
	0, 0, 5, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const char _emoji_presentation_from_state_actions[] = {
	0, 0, 6, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const char _emoji_presentation_eof_trans[] = {
	1, 4, 0, 1, 18, 1, 18, 1, 
	18, 20, 24, 25, 18
};

static const int emoji_presentation_start = 2;

static const int emoji_presentation_en_text_and_emoji_run = 2;


#line 26 "emoji_presentation_scanner.rl"



#line 106 "emoji_presentation_scanner.rl"


EMOJI_LINKAGE emoji_text_iter_t
scan_emoji_presentation (emoji_text_iter_t p,
    const emoji_text_iter_t pe,
    bool* is_emoji,
    bool* has_vs)
{
  emoji_text_iter_t ts;
  emoji_text_iter_t te;
  const emoji_text_iter_t eof = pe;

  (void)ts;

  unsigned act;
  int cs;

  
#line 113 "emoji_presentation_scanner.c"
	{
	cs = emoji_presentation_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 121 "emoji_presentation_scanner.c"
	{
	int _slen;
	int _trans;
	const unsigned char *_keys;
	const char *_inds;
	if ( p == pe )
		goto _test_eof;
_resume:
	switch ( _emoji_presentation_from_state_actions[cs] ) {
	case 6:
#line 1 "NONE"
	{ts = p;}
	break;
#line 135 "emoji_presentation_scanner.c"
	}

	_keys = _emoji_presentation_trans_keys + (cs<<1);
	_inds = _emoji_presentation_indicies + _emoji_presentation_index_offsets[cs];

	_slen = _emoji_presentation_key_spans[cs];
	_trans = _inds[ _slen > 0 && _keys[0] <=(*p) &&
		(*p) <= _keys[1] ?
		(*p) - _keys[0] : _slen ];

_eof_trans:
	cs = _emoji_presentation_trans_targs[_trans];

	if ( _emoji_presentation_trans_actions[_trans] == 0 )
		goto _again;

	switch ( _emoji_presentation_trans_actions[_trans] ) {
	case 9:
#line 99 "emoji_presentation_scanner.rl"
	{te = p+1;{ *is_emoji = false; *has_vs = true; return te; }}
	break;
	case 16:
#line 100 "emoji_presentation_scanner.rl"
	{te = p+1;{ *is_emoji = true; *has_vs = true; return te; }}
	break;
	case 4:
#line 101 "emoji_presentation_scanner.rl"
	{te = p+1;{ *is_emoji = true; *has_vs = false; return te; }}
	break;
	case 13:
#line 102 "emoji_presentation_scanner.rl"
	{te = p+1;{ *is_emoji = true;  *has_vs = false; return te; }}
	break;
	case 8:
#line 103 "emoji_presentation_scanner.rl"
	{te = p+1;{ *is_emoji = false; *has_vs = false; return te; }}
	break;
	case 14:
#line 99 "emoji_presentation_scanner.rl"
	{te = p;p--;{ *is_emoji = false; *has_vs = true; return te; }}
	break;
	case 15:
#line 100 "emoji_presentation_scanner.rl"
	{te = p;p--;{ *is_emoji = true; *has_vs = true; return te; }}
	break;
	case 11:
#line 101 "emoji_presentation_scanner.rl"
	{te = p;p--;{ *is_emoji = true; *has_vs = false; return te; }}
	break;
	case 12:
#line 103 "emoji_presentation_scanner.rl"
	{te = p;p--;{ *is_emoji = false; *has_vs = false; return te; }}
	break;
	case 3:
#line 101 "emoji_presentation_scanner.rl"
	{{p = ((te))-1;}{ *is_emoji = true; *has_vs = false; return te; }}
	break;
	case 1:
#line 1 "NONE"
	{	switch( act ) {
	case 2:
	{{p = ((te))-1;} *is_emoji = true; *has_vs = true; return te; }
	break;
	case 3:
	{{p = ((te))-1;} *is_emoji = true; *has_vs = false; return te; }
	break;
	case 5:
	{{p = ((te))-1;} *is_emoji = false; *has_vs = false; return te; }
	break;
	}
	}
	break;
	case 10:
#line 1 "NONE"
	{te = p+1;}
#line 100 "emoji_presentation_scanner.rl"
	{act = 2;}
	break;
	case 2:
#line 1 "NONE"
	{te = p+1;}
#line 101 "emoji_presentation_scanner.rl"
	{act = 3;}
	break;
	case 7:
#line 1 "NONE"
	{te = p+1;}
#line 103 "emoji_presentation_scanner.rl"
	{act = 5;}
	break;
#line 226 "emoji_presentation_scanner.c"
	}

_again:
	switch ( _emoji_presentation_to_state_actions[cs] ) {
	case 5:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 235 "emoji_presentation_scanner.c"
	}

	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _emoji_presentation_eof_trans[cs] > 0 ) {
		_trans = _emoji_presentation_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	}

#line 126 "emoji_presentation_scanner.rl"


  /* Should not be reached. */
  *is_emoji = false;
  *has_vs = false;
  return p;
}
