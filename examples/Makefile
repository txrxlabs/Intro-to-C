CFLAGS=-W -Wall -g

PRODUCTS=0001-hello 0002-integer-variables \
	0003-variable-types \
	0003a-using-scanf \
	0004-assignment-statement \
	0005-bitwise-operators \
	0006-relational-operators \
	0007-for-loop \
	0008-if-statement \
	0008a-switch-statement \
	0009-while-loop \
	0010-do-while \
	0011-functions \
	0012-functions \
	0013-pseudo-random-numbers \
	0014-pointers \
	0015-strings \
	0016-strings2 \
	0017-arrays-pointer-arithmetic \
	0018-more-pointer-arithmetic \
	0019-structs \
	0020-more-structs \
	0020b-malloc-and-free \
	0021-input-output \
	0022-more-input-output \
	0023-input-output-3 \
	0024-strings3 \
	0025-display-module.o \
	0025-display-module-client

all:	${PRODUCTS}

0025-display-module-client: 0025-display-module-client.c 0025-display-module.o
	gcc ${CFLAGS} -o 0025-display-module-client 0025-display-module.o 0025-display-module-client.c

clean:
	rm -f ${PRODUCTS}
