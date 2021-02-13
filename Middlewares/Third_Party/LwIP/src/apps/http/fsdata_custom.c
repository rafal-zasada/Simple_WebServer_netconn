#include "fs.h"
#include "lwip/def.h"
#include "fsdata.h"


#define file_NULL (struct fsdata_file *) NULL


static const unsigned int dummy_align__cs_styles_css = 0;
static const unsigned char data__cs_styles_css[] = {
/* /cs/styles.css (15 chars) */
0x2f,0x63,0x73,0x2f,0x73,0x74,0x79,0x6c,0x65,0x73,0x2e,0x63,0x73,0x73,0x00,0x00,

/* HTTP header */
/* "HTTP/1.0 200 OK
" (17 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x32,0x30,0x30,0x20,0x4f,0x4b,0x0d,
0x0a,
/* "Server: lwIP/1.3.1 (http://savannah.nongnu.org/projects/lwip)
" (63 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x31,0x2e,0x33,
0x2e,0x31,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,0x6e,
0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,0x70,
0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,
/* "Content-type: text/css

" (26 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x74,0x79,0x70,0x65,0x3a,0x20,0x74,0x65,
0x78,0x74,0x2f,0x63,0x73,0x73,0x0d,0x0a,0x0d,0x0a,
/* raw file data (306 bytes) */
0x23,0x62,0x74,0x6e,0x31,0x7b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x6d,0x6f,
0x63,0x63,0x61,0x73,0x69,0x6e,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x66,0x6f,0x6e,
0x74,0x2d,0x66,0x61,0x6d,0x69,0x6c,0x79,0x3a,0x20,0x41,0x72,0x69,0x61,0x6c,0x2c,
0x20,0x48,0x65,0x6c,0x76,0x65,0x74,0x69,0x63,0x61,0x2c,0x20,0x73,0x61,0x6e,0x73,
0x2d,0x73,0x65,0x72,0x69,0x66,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x63,0x6f,0x6c,
0x6f,0x72,0x3a,0x20,0x72,0x67,0x62,0x28,0x30,0x2c,0x20,0x30,0x2c,0x20,0x30,0x29,
0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x70,0x61,0x64,0x64,0x69,0x6e,0x67,0x3a,0x20,
0x31,0x30,0x70,0x78,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,
0x72,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x6d,0x6f,0x63,0x63,0x61,0x73,0x69,
0x6e,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x66,0x6f,0x6e,0x74,0x2d,0x73,0x69,0x7a,
0x65,0x3a,0x20,0x31,0x32,0x70,0x78,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x66,0x6f,
0x6e,0x74,0x2d,0x77,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x62,0x6f,0x6c,0x64,0x3b,
0x0d,0x0a,0x7d,0x0d,0x0a,0x0d,0x0a,0x68,0x31,0x7b,0x0d,0x0a,0x20,0x20,0x20,0x20,
0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,
0x3a,0x20,0x72,0x67,0x62,0x28,0x32,0x30,0x32,0x2c,0x20,0x32,0x30,0x36,0x2c,0x20,
0x31,0x39,0x38,0x29,0x3b,0x0d,0x0a,0x7d,0x0d,0x0a,0x0d,0x0a,0x2e,0x68,0x69,0x64,
0x65,0x2d,0x6d,0x65,0x20,0x7b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x76,0x69,0x73,0x69,
0x62,0x69,0x6c,0x69,0x74,0x79,0x3a,0x20,0x68,0x69,0x64,0x64,0x65,0x6e,0x3b,0x0d,
0x0a,0x7d,};

static const unsigned int dummy_align__js_main_js = 1;
static const unsigned char data__js_main_js[] = {
/* /js/main.js (12 chars) */
0x2f,0x6a,0x73,0x2f,0x6d,0x61,0x69,0x6e,0x2e,0x6a,0x73,0x00,

/* HTTP header */
/* "HTTP/1.0 200 OK
" (17 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x32,0x30,0x30,0x20,0x4f,0x4b,0x0d,
0x0a,
/* "Server: lwIP/1.3.1 (http://savannah.nongnu.org/projects/lwip)
" (63 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x31,0x2e,0x33,
0x2e,0x31,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,0x6e,
0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,0x70,
0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,
/* "Content-type: application/x-javascript

" (42 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x74,0x79,0x70,0x65,0x3a,0x20,0x61,0x70,
0x70,0x6c,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,0x2f,0x78,0x2d,0x6a,0x61,0x76,0x61,
0x73,0x63,0x72,0x69,0x70,0x74,0x0d,0x0a,0x0d,0x0a,
/* raw file data (1465 bytes) */
0x0d,0x0a,0x76,0x61,0x72,0x20,0x61,0x6e,0x69,0x6d,0x61,0x6c,0x43,0x6f,0x6e,0x74,
0x61,0x69,0x6e,0x65,0x72,0x20,0x3d,0x20,0x64,0x6f,0x63,0x75,0x6d,0x65,0x6e,0x74,
0x2e,0x67,0x65,0x74,0x45,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x42,0x79,0x49,0x64,0x28,
0x22,0x61,0x6e,0x69,0x6d,0x61,0x6c,0x2d,0x69,0x6e,0x66,0x6f,0x22,0x29,0x3b,0x0d,
0x0a,0x76,0x61,0x72,0x20,0x62,0x74,0x6e,0x31,0x20,0x3d,0x20,0x64,0x6f,0x63,0x75,
0x6d,0x65,0x6e,0x74,0x2e,0x67,0x65,0x74,0x45,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x42,
0x79,0x49,0x64,0x28,0x22,0x62,0x74,0x6e,0x31,0x22,0x29,0x3b,0x0d,0x0a,0x76,0x61,
0x72,0x20,0x70,0x61,0x67,0x65,0x43,0x6f,0x75,0x6e,0x74,0x65,0x72,0x20,0x3d,0x20,
0x31,0x3b,0x0d,0x0a,0x0d,0x0a,0x62,0x74,0x6e,0x31,0x2e,0x61,0x64,0x64,0x45,0x76,
0x65,0x6e,0x74,0x4c,0x69,0x73,0x74,0x65,0x6e,0x65,0x72,0x28,0x22,0x63,0x6c,0x69,
0x63,0x6b,0x22,0x2c,0x20,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x28,0x29,0x20,
0x7b,0x20,0x20,0x2f,0x2f,0x20,0x74,0x68,0x69,0x73,0x20,0x69,0x73,0x20,0x61,0x6e,
0x20,0x61,0x6e,0x6f,0x6e,0x79,0x6d,0x6f,0x75,0x73,0x20,0x66,0x75,0x63,0x74,0x69,
0x6f,0x6e,0x20,0x2d,0x20,0x6e,0x6f,0x74,0x20,0x61,0x20,0x67,0x6f,0x6f,0x64,0x20,
0x70,0x72,0x61,0x63,0x74,0x69,0x63,0x65,0x0d,0x0a,0x0d,0x0a,0x20,0x20,0x20,0x20,
0x76,0x61,0x72,0x20,0x6f,0x75,0x72,0x52,0x65,0x71,0x75,0x65,0x73,0x74,0x31,0x20,
0x3d,0x20,0x6e,0x65,0x77,0x20,0x58,0x4d,0x4c,0x48,0x74,0x74,0x70,0x52,0x65,0x71,
0x75,0x65,0x73,0x74,0x28,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x72,
0x52,0x65,0x71,0x75,0x65,0x73,0x74,0x31,0x2e,0x6f,0x70,0x65,0x6e,0x28,0x27,0x47,
0x45,0x54,0x27,0x2c,0x20,0x27,0x68,0x74,0x74,0x70,0x73,0x3a,0x2f,0x2f,0x6c,0x65,
0x61,0x72,0x6e,0x77,0x65,0x62,0x63,0x6f,0x64,0x65,0x2e,0x67,0x69,0x74,0x68,0x75,
0x62,0x2e,0x69,0x6f,0x2f,0x6a,0x73,0x6f,0x6e,0x2d,0x65,0x78,0x61,0x6d,0x70,0x6c,
0x65,0x2f,0x61,0x6e,0x69,0x6d,0x61,0x6c,0x73,0x2d,0x31,0x2e,0x6a,0x73,0x6f,0x6e,
0x27,0x29,0x0d,0x0a,0x20,0x20,0x20,0x20,0x6f,0x75,0x72,0x52,0x65,0x71,0x75,0x65,
0x73,0x74,0x31,0x2e,0x6f,0x6e,0x6c,0x6f,0x61,0x64,0x20,0x3d,0x20,0x66,0x75,0x6e,
0x63,0x74,0x69,0x6f,0x6e,0x28,0x29,0x20,0x7b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,
0x2f,0x2f,0x20,0x20,0x20,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,0x6c,0x6f,0x67,
0x28,0x6f,0x75,0x72,0x52,0x65,0x71,0x75,0x65,0x73,0x74,0x31,0x2e,0x72,0x65,0x73,
0x70,0x6f,0x6e,0x73,0x65,0x54,0x65,0x78,0x74,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,
0x20,0x20,0x2f,0x2f,0x20,0x76,0x61,0x72,0x20,0x6f,0x75,0x72,0x44,0x61,0x74,0x61,
0x31,0x20,0x3d,0x20,0x6f,0x75,0x72,0x52,0x65,0x71,0x75,0x65,0x73,0x74,0x31,0x2e,
0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x54,0x65,0x78,0x74,0x3b,0x20,0x20,0x2f,
0x2f,0x20,0x6a,0x75,0x73,0x74,0x20,0x66,0x6f,0x74,0x20,0x74,0x65,0x78,0x74,0x20,
0x74,0x79,0x70,0x65,0x20,0x64,0x61,0x74,0x61,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,
0x76,0x61,0x72,0x20,0x6f,0x75,0x72,0x44,0x61,0x74,0x61,0x31,0x20,0x3d,0x20,0x4a,
0x53,0x4f,0x4e,0x2e,0x70,0x61,0x72,0x73,0x65,0x28,0x6f,0x75,0x72,0x52,0x65,0x71,
0x75,0x65,0x73,0x74,0x31,0x2e,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x54,0x65,
0x78,0x74,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x2f,0x2f,0x63,0x6f,0x6e,0x73,
0x6f,0x6c,0x65,0x2e,0x6c,0x6f,0x67,0x28,0x6f,0x75,0x72,0x44,0x61,0x74,0x61,0x31,
0x5b,0x30,0x5d,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x6e,0x64,0x65,
0x72,0x48,0x54,0x4d,0x4c,0x31,0x28,0x6f,0x75,0x72,0x44,0x61,0x74,0x61,0x31,0x29,
0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x7d,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0x6f,0x75,0x72,0x52,0x65,0x71,0x75,0x65,0x73,0x74,0x31,0x2e,0x73,
0x65,0x6e,0x64,0x28,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x70,0x61,0x67,0x65,0x43,0x6f,0x75,0x6e,0x74,0x65,0x72,0x2b,0x2b,0x3b,0x0d,0x0a,
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x69,0x66,0x28,0x70,0x61,0x67,0x65,0x43,
0x6f,0x75,0x6e,0x74,0x65,0x72,0x20,0x3e,0x20,0x33,0x29,0x20,0x7b,0x0d,0x0a,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x62,0x74,0x6e,0x31,0x2e,
0x63,0x6c,0x61,0x73,0x73,0x4c,0x69,0x73,0x74,0x2e,0x61,0x64,0x64,0x28,0x22,0x68,
0x69,0x64,0x65,0x2d,0x6d,0x65,0x22,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0x7d,0x0d,0x0a,0x7d,0x29,0x3b,0x0d,0x0a,0x0d,0x0a,0x66,0x75,0x6e,
0x63,0x74,0x69,0x6f,0x6e,0x20,0x72,0x65,0x6e,0x64,0x65,0x72,0x48,0x54,0x4d,0x4c,
0x31,0x28,0x64,0x61,0x74,0x61,0x29,0x20,0x7b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x76,
0x61,0x72,0x20,0x68,0x74,0x6d,0x6c,0x53,0x74,0x72,0x69,0x6e,0x67,0x31,0x20,0x3d,
0x20,0x22,0x52,0x61,0x66,0x61,0x6c,0x31,0x22,0x3b,0x0d,0x0a,0x0d,0x0a,0x20,0x20,
0x20,0x20,0x66,0x6f,0x72,0x28,0x69,0x20,0x3d,0x20,0x30,0x3b,0x20,0x69,0x20,0x3c,
0x20,0x64,0x61,0x74,0x61,0x2e,0x6c,0x65,0x6e,0x67,0x74,0x68,0x20,0x3b,0x20,0x69,
0x2b,0x2b,0x29,0x20,0x7b,0x0d,0x0a,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x20,0x68,0x74,0x6d,0x6c,0x53,0x74,0x72,0x69,0x6e,0x67,0x31,0x20,0x2b,0x3d,0x20,
0x22,0x3c,0x70,0x3e,0x22,0x20,0x2b,0x20,0x64,0x61,0x74,0x61,0x5b,0x69,0x5d,0x2e,
0x6e,0x61,0x6d,0x65,0x20,0x2b,0x20,0x22,0x69,0x73,0x20,0x61,0x20,0x22,0x20,0x2b,
0x20,0x64,0x61,0x74,0x61,0x5b,0x69,0x5d,0x2e,0x73,0x70,0x65,0x63,0x69,0x65,0x73,
0x20,0x2b,0x20,0x22,0x2e,0x3c,0x2f,0x70,0x3e,0x22,0x3b,0x0d,0x0a,0x20,0x20,0x20,
0x20,0x20,0x20,0x20,0x20,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,0x6c,0x6f,0x67,
0x28,0x69,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0d,0x0a,0x0d,0x0a,0x0d,
0x0a,0x61,0x6e,0x69,0x6d,0x61,0x6c,0x43,0x6f,0x6e,0x74,0x61,0x69,0x6e,0x65,0x72,
0x2e,0x69,0x6e,0x73,0x65,0x72,0x74,0x41,0x64,0x6a,0x61,0x63,0x65,0x6e,0x74,0x48,
0x54,0x4d,0x4c,0x28,0x27,0x62,0x65,0x66,0x6f,0x72,0x65,0x65,0x6e,0x64,0x27,0x2c,
0x20,0x68,0x74,0x6d,0x6c,0x53,0x74,0x72,0x69,0x6e,0x67,0x31,0x29,0x3b,0x0d,0x0a,
0x7d,0x0d,0x0a,0x0d,0x0a,0x2f,0x2a,0x0d,0x0a,0x0d,0x0a,0x2f,0x2f,0x20,0x52,0x65,
0x74,0x75,0x72,0x6e,0x73,0x20,0x61,0x20,0x50,0x72,0x6f,0x6d,0x69,0x73,0x65,0x20,
0x74,0x68,0x61,0x74,0x20,0x72,0x65,0x73,0x6f,0x6c,0x76,0x65,0x73,0x20,0x61,0x66,
0x74,0x65,0x72,0x20,0x22,0x6d,0x73,0x22,0x20,0x4d,0x69,0x6c,0x6c,0x69,0x73,0x65,
0x63,0x6f,0x6e,0x64,0x73,0x0d,0x0a,0x63,0x6f,0x6e,0x73,0x74,0x20,0x74,0x69,0x6d,
0x65,0x72,0x20,0x3d,0x20,0x6d,0x73,0x20,0x3d,0x3e,0x20,0x6e,0x65,0x77,0x20,0x50,
0x72,0x6f,0x6d,0x69,0x73,0x65,0x28,0x72,0x65,0x73,0x20,0x3d,0x3e,0x20,0x73,0x65,
0x74,0x54,0x69,0x6d,0x65,0x6f,0x75,0x74,0x28,0x72,0x65,0x73,0x2c,0x20,0x6d,0x73,
0x29,0x29,0x0d,0x0a,0x0d,0x0a,0x61,0x73,0x79,0x6e,0x63,0x20,0x66,0x75,0x6e,0x63,
0x74,0x69,0x6f,0x6e,0x20,0x6c,0x6f,0x61,0x64,0x20,0x28,0x29,0x20,0x7b,0x20,0x2f,
0x2f,0x20,0x57,0x65,0x20,0x6e,0x65,0x65,0x64,0x20,0x74,0x6f,0x20,0x77,0x72,0x61,
0x70,0x20,0x74,0x68,0x65,0x20,0x6c,0x6f,0x6f,0x70,0x20,0x69,0x6e,0x74,0x6f,0x20,
0x61,0x6e,0x20,0x61,0x73,0x79,0x6e,0x63,0x20,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,
0x6e,0x20,0x66,0x6f,0x72,0x20,0x74,0x68,0x69,0x73,0x20,0x74,0x6f,0x20,0x77,0x6f,
0x72,0x6b,0x0d,0x0a,0x20,0x20,0x66,0x6f,0x72,0x20,0x28,0x76,0x61,0x72,0x20,0x69,
0x20,0x3d,0x20,0x30,0x3b,0x20,0x69,0x20,0x3c,0x20,0x33,0x3b,0x20,0x69,0x2b,0x2b,
0x29,0x20,0x7b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,
0x2e,0x6c,0x6f,0x67,0x28,0x69,0x29,0x3b,0x0d,0x0a,0x20,0x20,0x20,0x20,0x61,0x77,
0x61,0x69,0x74,0x20,0x74,0x69,0x6d,0x65,0x72,0x28,0x31,0x30,0x30,0x30,0x29,0x3b,
0x20,0x2f,0x2f,0x20,0x74,0x68,0x65,0x6e,0x20,0x74,0x68,0x65,0x20,0x63,0x72,0x65,
0x61,0x74,0x65,0x64,0x20,0x50,0x72,0x6f,0x6d,0x69,0x73,0x65,0x20,0x63,0x61,0x6e,
0x20,0x62,0x65,0x20,0x61,0x77,0x61,0x69,0x74,0x65,0x64,0x0d,0x0a,0x20,0x20,0x7d,
0x0d,0x0a,0x7d,0x0d,0x0a,0x0d,0x0a,0x2a,0x2f,};

static const unsigned int dummy_align__index_html = 2;
static const unsigned char data__index_html[] = {
/* /index.html (12 chars) */
0x2f,0x69,0x6e,0x64,0x65,0x78,0x2e,0x68,0x74,0x6d,0x6c,0x00,

/* HTTP header */
/* "HTTP/1.0 200 OK
" (17 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x32,0x30,0x30,0x20,0x4f,0x4b,0x0d,
0x0a,
/* "Server: lwIP/1.3.1 (http://savannah.nongnu.org/projects/lwip)
" (63 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x31,0x2e,0x33,
0x2e,0x31,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,0x6e,
0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,0x70,
0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,
/* "Content-type: text/html

" (27 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x74,0x79,0x70,0x65,0x3a,0x20,0x74,0x65,
0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x0d,0x0a,0x0d,0x0a,
/* raw file data (483 bytes) */
0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x68,0x74,0x6d,0x6c,0x3e,0x0d,
0x0a,0x3c,0x68,0x74,0x6d,0x6c,0x20,0x6c,0x61,0x6e,0x67,0x3d,0x22,0x65,0x6e,0x22,
0x3e,0x0d,0x0a,0x3c,0x68,0x65,0x61,0x64,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,
0x6d,0x65,0x74,0x61,0x20,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x22,0x55,0x54,
0x46,0x2d,0x38,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,
0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x76,0x69,0x65,0x77,0x70,0x6f,0x72,0x74,0x22,
0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x77,0x69,0x64,0x74,0x68,0x3d,
0x64,0x65,0x76,0x69,0x63,0x65,0x2d,0x77,0x69,0x64,0x74,0x68,0x2c,0x20,0x69,0x6e,
0x69,0x74,0x69,0x61,0x6c,0x2d,0x73,0x63,0x61,0x6c,0x65,0x3d,0x31,0x2e,0x30,0x22,
0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,0x3e,0x44,0x6f,
0x63,0x75,0x6d,0x65,0x6e,0x74,0x20,0x69,0x2e,0x65,0x2e,0x20,0x6d,0x79,0x20,0x64,
0x6f,0x63,0x75,0x6d,0x65,0x6e,0x74,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0d,
0x0a,0x20,0x20,0x20,0x20,0x3c,0x6c,0x69,0x6e,0x6b,0x20,0x72,0x65,0x6c,0x3d,0x22,
0x73,0x74,0x79,0x6c,0x65,0x73,0x68,0x65,0x65,0x74,0x22,0x20,0x68,0x72,0x65,0x66,
0x3d,0x22,0x63,0x73,0x2f,0x73,0x74,0x79,0x6c,0x65,0x73,0x2e,0x63,0x73,0x73,0x22,
0x3e,0x0d,0x0a,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0d,0x0a,0x3c,0x62,0x6f,0x64,
0x79,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x68,0x65,0x61,0x64,0x65,0x72,0x3e,
0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x68,0x31,0x3e,0x4d,0x79,
0x20,0x77,0x65,0x62,0x73,0x69,0x74,0x65,0x20,0x31,0x31,0x31,0x3c,0x2f,0x68,0x31,
0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x62,0x75,0x74,0x74,
0x6f,0x6e,0x20,0x69,0x64,0x3d,0x22,0x62,0x74,0x6e,0x31,0x22,0x3e,0x46,0x65,0x74,
0x63,0x68,0x20,0x69,0x6e,0x66,0x6f,0x20,0x66,0x6f,0x72,0x20,0x33,0x20,0x4e,0x65,
0x77,0x20,0x61,0x6e,0x69,0x6d,0x61,0x6c,0x73,0x3c,0x2f,0x62,0x75,0x74,0x74,0x6f,
0x6e,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x65,0x72,
0x3e,0x0d,0x0a,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x64,0x69,0x76,0x20,0x69,0x64,
0x3d,0x22,0x61,0x6e,0x69,0x6d,0x61,0x6c,0x2d,0x69,0x6e,0x66,0x6f,0x22,0x3e,0x3c,
0x2f,0x64,0x69,0x76,0x3e,0x0d,0x0a,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x73,0x63,
0x72,0x69,0x70,0x74,0x20,0x73,0x72,0x63,0x3d,0x22,0x6a,0x73,0x2f,0x6d,0x61,0x69,
0x6e,0x2e,0x6a,0x73,0x22,0x3e,0x3c,0x2f,0x73,0x63,0x72,0x69,0x70,0x74,0x3e,0x0d,
0x0a,0x0d,0x0a,0x3c,0x2f,0x62,0x6f,0x64,0x79,0x3e,0x0d,0x0a,0x3c,0x2f,0x68,0x74,
0x6d,0x6c,0x3e,};



const struct fsdata_file file__cs_styles_css[] = { {
file_NULL,
data__cs_styles_css,
data__cs_styles_css + 16,
sizeof(data__cs_styles_css) - 16,
1,
}};

const struct fsdata_file file__js_main_js[] = { {
file__cs_styles_css,
data__js_main_js,
data__js_main_js + 12,
sizeof(data__js_main_js) - 12,
1,
}};

const struct fsdata_file file__index_html[] = { {
file__js_main_js,
data__index_html,
data__index_html + 12,
sizeof(data__index_html) - 12,
1,
}};

#define FS_ROOT file__index_html
#define FS_NUMFILES 3

