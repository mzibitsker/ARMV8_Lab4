	.globl arraysum, muladd, countchars, arraycopy


// arraysum(A,ct) computes the sim of ct elements from the array A

arraysum:
	mov x9, #0
loop:
	cbz x1, done
	ldur x10, [x0, #0]
	add x9, x9, x10
	sub x1, x1, #1
	add x0, x0, #8
	b loop
done:
	mov x0, x9
	ret


// muladd(x,y,z) computes x*y+z

muladd:
	mul x0, x1,x0
	add x0, x0, x2
	ret



// countchars(str,len,ch) counts the number of occurrences of ch in str; len is the length of str
// x0 contains string pointer, x1 contains string length, x2 contains character
countchars:
	// counter store in register x9
	mov X9, #0
	// index stored in register x11
	mov x11, #0
	loop1:
	// load string pointer into temp register 10
		LDURB w10, [x0,#0]
		// compare character, if true increment x9, if false increment index x11
		CMP x2, x10
		B.eq true
		B.ne false
			true:
				add X9, x9, #1
				B comp

			false:

					B comp

		// compare x1 and index
		comp:
			add x0, x0, #1
			add x11, x11, #1
			CMP x1, x11
			// if the same done
			B.eq done1
			B.ne loop1
	done1:
		mov x0, x9
		ret


// arraycopy(A,B,ct) copies ct elements from array A into array B

arraycopy:


// x0 is array A pointer
// x1 is array B pointer/
// x2 is number of elements we need to copy
//counter
	mov x9, #0

	loop2:

	// load element from A
	LDUR x10, [x0,#0]
	// store element from A in B
	STUR x10, [x1,#0]


// compare if x2 is equal to counter
	CMP x9, x2
		B.eq true1
		B.ne false1
		true1:
			B done2
		false1:
			add x9, x9, #1
			B inc
		inc:
			add x0, x0, #8
			add x1, x1, #8
			B loop2

    done2:
    	mov x0,x1
    ret
