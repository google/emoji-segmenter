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


#line 23 "emoji_presentation_scanner.c"
static const unsigned char _emoji_presentation_trans_keys[] = {
	0u, 12u, 13u, 14u, 0u, 12u, 8u, 11u,
	9u, 11u, 9u, 9u, 3u, 11u, 3u, 11u,
	5u, 5u, 8u, 11u, 7u, 9u, 8u, 13u,
	0u
};

static const signed char _emoji_presentation_char_class[] = {
	0, 0, 1, 2, 3, 4, 5, 6,
	7, 8, 9, 10, 11, 12, 13, 14,
	0
};

static const signed char _emoji_presentation_index_offsets[] = {
	0, 13, 15, 28, 32, 35, 36, 45,
	54, 55, 59, 62, 0
};

static const signed char _emoji_presentation_indices[] = {
	1, 1, 2, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 1, 4, 5, 7,
	8, 9, 10, 10, 11, 12, 10, 10,
	10, 10, 10, 13, 5, 14, 15, 16,
	14, 17, 16, 14, 16, 17, 17, 17,
	17, 17, 14, 17, 16, 16, 17, 17,
	17, 17, 5, 14, 15, 16, 5, 5,
	14, 15, 19, 5, 17, 14, 5, 14,
	15, 16, 17, 4, 0
};

static const signed char _emoji_presentation_index_defaults[] = {
	0, 3, 10, 0, 17, 17, 17, 17,
	18, 18, 17, 17, 0
};

static const signed char _emoji_presentation_cond_targs[] = {
	2, 4, 6, 2, 1, 2, 2, 3,
	3, 7, 2, 8, 9, 11, 0, 2,
	5, 2, 2, 10, 0
};

static const signed char _emoji_presentation_cond_actions[] = {
	1, 2, 2, 3, 0, 4, 0, 7,
	2, 2, 8, 0, 7, 2, 0, 9,
	2, 10, 11, 2, 0
};

static const signed char _emoji_presentation_to_state_actions[] = {
	0, 0, 5, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0
};

static const signed char _emoji_presentation_from_state_actions[] = {
	0, 0, 6, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0
};

static const signed char _emoji_presentation_eof_trans[] = {
	1, 4, 7, 1, 18, 18, 18, 18,
	19, 19, 18, 18, 0
};

static const int emoji_presentation_start = 2;

static const int emoji_presentation_en_text_and_emoji_run = 2;


#line 26 "emoji_presentation_scanner.rl"



#line 95 "emoji_presentation_scanner.rl"


EMOJI_LINKAGE emoji_text_iter_t
scan_emoji_presentation (emoji_text_iter_t p,
const emoji_text_iter_t pe,
bool* is_emoji)
{
	emoji_text_iter_t ts;
	emoji_text_iter_t te;
	const emoji_text_iter_t eof = pe;
	
	unsigned act;
	int cs;
	

#line 107 "emoji_presentation_scanner.c"
	{
		cs = (int)emoji_presentation_start;
		ts = 0;
		te = 0;
		act = 0;
	}

#line 113 "emoji_presentation_scanner.c"
	{
		unsigned int _trans = 0;
		const unsigned char * _keys;
		const signed char * _inds;
		int _ic;
		_resume: {}
		if ( p == pe && p != eof )
			goto _out;
		switch ( _emoji_presentation_from_state_actions[cs] ) {
			case 6:  {
					{
#line 1 "NONE"
					{ts = p;}}
				
#line 127 "emoji_presentation_scanner.c"

				
				break; 
			}
		}
		
		if ( p == eof ) {
			if ( _emoji_presentation_eof_trans[cs] > 0 ) {
				_trans = (unsigned int)_emoji_presentation_eof_trans[cs] - 1;
			}
		}
		else {
			_keys = ( _emoji_presentation_trans_keys + ((cs<<1)));
			_inds = ( _emoji_presentation_indices + (_emoji_presentation_index_offsets[cs]));
			
			if ( ( (*( p))) <= 15 ) {
				_ic = (int)_emoji_presentation_char_class[(int)( (*( p))) - 0];
				if ( _ic <= (int)(*( _keys+1)) && _ic >= (int)(*( _keys)) )
					_trans = (unsigned int)(*( _inds + (int)( _ic - (int)(*( _keys)) ) )); 
				else
					_trans = (unsigned int)_emoji_presentation_index_defaults[cs];
			}
			else {
				_trans = (unsigned int)_emoji_presentation_index_defaults[cs];
			}
			
		}
		cs = (int)_emoji_presentation_cond_targs[_trans];
		
		if ( _emoji_presentation_cond_actions[_trans] != 0 ) {
			
			switch ( _emoji_presentation_cond_actions[_trans] ) {
				case 9:  {
						{
#line 90 "emoji_presentation_scanner.rl"
						{te = p+1;{
#line 90 "emoji_presentation_scanner.rl"
								*is_emoji = false; return te; }
						}}
					
#line 167 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 4:  {
						{
#line 91 "emoji_presentation_scanner.rl"
						{te = p+1;{
#line 91 "emoji_presentation_scanner.rl"
								*is_emoji = true; return te; }
						}}
					
#line 179 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 8:  {
						{
#line 92 "emoji_presentation_scanner.rl"
						{te = p+1;{
#line 92 "emoji_presentation_scanner.rl"
								*is_emoji = false; return te; }
						}}
					
#line 191 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 10:  {
						{
#line 91 "emoji_presentation_scanner.rl"
						{te = p;p = p - 1;{
#line 91 "emoji_presentation_scanner.rl"
								*is_emoji = true; return te; }
						}}
					
#line 203 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 11:  {
						{
#line 92 "emoji_presentation_scanner.rl"
						{te = p;p = p - 1;{
#line 92 "emoji_presentation_scanner.rl"
								*is_emoji = false; return te; }
						}}
					
#line 215 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 3:  {
						{
#line 91 "emoji_presentation_scanner.rl"
						{p = ((te))-1;
							{
#line 91 "emoji_presentation_scanner.rl"
								*is_emoji = true; return te; }
						}}
					
#line 228 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 1:  {
						{
#line 1 "NONE"
						{switch( act ) {
								case 2:  {
									p = ((te))-1;
									{
#line 91 "emoji_presentation_scanner.rl"
										*is_emoji = true; return te; }
									break; 
								}
								case 3:  {
									p = ((te))-1;
									{
#line 92 "emoji_presentation_scanner.rl"
										*is_emoji = false; return te; }
									break; 
								}
							}}
					}
					
#line 253 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 2:  {
						{
#line 1 "NONE"
						{te = p+1;}}
					
#line 262 "emoji_presentation_scanner.c"

						{
#line 91 "emoji_presentation_scanner.rl"
						{act = 2;}}
					
#line 267 "emoji_presentation_scanner.c"

					
					break; 
				}
				case 7:  {
						{
#line 1 "NONE"
						{te = p+1;}}
					
#line 276 "emoji_presentation_scanner.c"

						{
#line 92 "emoji_presentation_scanner.rl"
						{act = 3;}}
					
#line 281 "emoji_presentation_scanner.c"

					
					break; 
				}
			}
			
		}
		
		if ( p == eof ) {
			if ( cs >= 2 )
				goto _out;
		}
		else {
			switch ( _emoji_presentation_to_state_actions[cs] ) {
				case 5:  {
						{
#line 1 "NONE"
						{ts = 0;}}
					
#line 300 "emoji_presentation_scanner.c"

					
					break; 
				}
			}
			
			p += 1;
			goto _resume;
		}
		_out: {}
	}
	
#line 112 "emoji_presentation_scanner.rl"

	
	/* Should not be reached. */
	*is_emoji = false;
	return p;
}
