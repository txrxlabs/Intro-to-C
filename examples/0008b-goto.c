/*


C has a goto statement.

You may have heard that using "goto" is bad form.  

The "goto" statement is C is followed by a label.

Example:

	goto somewhere;

elsewhere in your code, you define the label:

somewhere:
	printf("We got to somewhere.\n");


Note the label must be in the same function as the goto.
You cannot cross function boundaries with goto.

Ordinarily, it is pretty good advice to avoid using goto.

There is one common pattern in which the use of
"goto" can be beneficial.

You might have to do some sequence of things to set up
for some particular operation, and afterwards undo all
the this setup.  There may be many steps in the setup.
If any part of the setup fails, you may have to undo
all that has been done so far.

For example, maybe you have a function like:

void do_something()
{
	do_setup_1();
	do_setup_2();
	do_setup_3();

	do_some_operation();

	undo_setup3();
	undo_setup2();
	undo_setup1();
	return;
}

But, what if some part of that setup fails?  You could rewrite it 
as:

void do_something()
{
	if (do_setup_1() != 0)
		return;
	if (do_setup_2() != 0) {
		undo_setup1();
		return;
	}
	if (do_setup_3() != 0) {
		undo_setup2();
		undo_setup1();
		return;
	}

	do_some_operation();

	undo_setup3();
	undo_setup2();
	undo_setup1();
	return;
}

Or, you could write it as:

void do_something()
{
	if (do_setup_1() != 0)
		goto setup1_failed;
	if (do_setup_2() != 0)
		goto setup2_failed;
	if (do_setup_3() != 0)
		goto setup3_failed;

	do_some_operation();

	undo_setup3();

setup3_failed:
	undo_setup2();
setup2_failed:
	undo_setup1();
setup1_failed:
	return;
}

This latter way is a fairly common pattern.  If you had to later
add some new setup code between setup1 and setup2 in the above
code, the code with the gotos would be easier to modify and 
harder to screw up  because you wouldn't have to touch multiple
"undo" paths as you would with the first implementation.

*/
