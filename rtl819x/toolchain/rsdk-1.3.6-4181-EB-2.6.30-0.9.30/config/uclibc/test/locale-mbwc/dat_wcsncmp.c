/*
 *  TEST SUITE FOR MB/WC FUNCTIONS IN C LIBRARY
 *
 *	 FILE:	dat_wcsncmp.c
 *
 *	 WCSNCMP:  int wcsncmp (const wchar_t *ws1, const wchar_t *ws2,
 *				size_t n);
 */

TST_WCSNCMP tst_wcsncmp_loc [] = {
  {
    { Twcsncmp, TST_LOC_de },
    {
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x00D1,0x00D2,0x00D3,0x0000 }, 4 },  /* #01 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x00D1,0x00D2,0x00D3,0x0000 }, 3 },  /* #02 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D1,0x0000 },
		     { 0x00D1,0x00D2,0x00D3,0x0000 }, 2 },  /* #03 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x00D0,0x00D2,0x00D3,0x0000 }, 0 },  /* #04 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0000,0x00D2,0x00D3,0x0000 },
		     { 0x0000,0x00D2,0x00D1,0x0000 }, 3 },  /* #05 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x0000,0x00D2,0x00D3,0x0000 }, 3 },  /* #06 */
	/*expect*/ { 0,1,0x00D1,			},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x00D1,0x00D2,0x00D9,0x0000 }, 2 },  /* #07 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x00D1,0x00D2,0x00D9,0x0000 }, 3 },  /* #08 */
	/*expect*/ { 0,1,-0x0006,			},
      },
      { /*input.*/ { { 0x00D1,0x00D2,0x00D3,0x0000 },
		     { 0x00D1,0x00D2,0x0000	   }, 4 },  /* #09 */
	/*expect*/ { 0,1,0x00D3,			},
      },
      { .is_last = 1 }
    }
  },
  {
    { Twcsncmp, TST_LOC_enUS },
    {
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0041,0x0042,0x0043,0x0000 }, 4 },  /* #01 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0041,0x0042,0x0043,0x0000 }, 3 },  /* #02 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0041,0x0000 },
		     { 0x0041,0x0042,0x0043,0x0000 }, 2 },  /* #03 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0040,0x0042,0x0043,0x0000 }, 0 },  /* #04 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0000,0x0042,0x0043,0x0000 },
		     { 0x0000,0x0042,0x0041,0x0000 }, 3 },  /* #05 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0000,0x0042,0x0043,0x0000 }, 3 },  /* #06 */
	/*expect*/ { 0,1,0x0041,			},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0041,0x0042,0x0049,0x0000 }, 2 },  /* #07 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0041,0x0042,0x0049,0x0000 }, 3 },  /* #08 */
	/*expect*/ { 0,1,-0x0006,			},
      },
      { /*input.*/ { { 0x0041,0x0042,0x0043,0x0000 },
		     { 0x0041,0x0042,0x0000	   }, 4 },  /* #09 */
	/*expect*/ { 0,1,0x0043,			},
      },
      { .is_last = 1 }
    }
  },
  {
#if 0
    { Twcsncmp, TST_LOC_eucJP },
#else
    { Twcsncmp, TST_LOC_ja_UTF8 },
#endif
    {
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x3041,0x3042,0x3043,0x0000 }, 4 },  /* #01 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x3041,0x3042,0x3043,0x0000 }, 3 },  /* #02 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3041,0x0000 },
		     { 0x3041,0x3042,0x3043,0x0000 }, 2 },  /* #03 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x3040,0x3042,0x3043,0x0000 }, 0 },  /* #04 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x0000,0x3042,0x3043,0x0000 },
		     { 0x0000,0x3042,0x3041,0x0000 }, 3 },  /* #05 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x0000,0x3042,0x3043,0x0000 }, 3 },  /* #06 */
	/*expect*/ { 0,1,0x3041,			},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x3041,0x3042,0x3049,0x0000 }, 2 },  /* #07 */
	/*expect*/ { 0,1,0,				},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x3041,0x3042,0x3049,0x0000 }, 3 },  /* #08 */
	/*expect*/ { 0,1,-0x0006,			},
      },
      { /*input.*/ { { 0x3041,0x3042,0x3043,0x0000 },
		     { 0x3041,0x3042,0x0000	   }, 4 },  /* #09 */
	/*expect*/ { 0,1,0x3043,			},
      },
      { .is_last = 1 }
    }
  },
  {
    { Twcsncmp, TST_LOC_end }
  }
};
