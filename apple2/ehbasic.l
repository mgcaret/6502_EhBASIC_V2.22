MEMORY {
	LOAD1: start = $2000, size = $3F00;
	RUN1: start = $8900, size = $3500;
	GLOBAL1: start = $BE00, size = $100;
}

SEGMENTS {
	loader: load = LOAD1, align = $100;
	global: load = LOAD1, run = GLOBAL1, define = yes, align = $100;
	interp: load = LOAD1, run = RUN1, define = yes, align = $100;
	code:	load = LOAD1;
}
