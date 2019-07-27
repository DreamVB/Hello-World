# Strong Password Generator
A small password generator for creating single or lists of random passwords.

<h2>Building the program</h2>

<h3>Running from the command line in Linux</h3>

<code>
  gcc -o bpwsgen bpwsgen.c
</code>

<h2>Usage</h2>

<h3>Running from the command line</h3>

<code>
  ./bpwsgen 8 1 /u /l /d
</code>

<h4>Create a strong password with optional options</h4>

<pre>
<code>
    <b>Options::</b>
    /U Include upper case characters A-Z
    /L Include lower case characters a-z
    /D Include digits 0-9
    /S Include special characters
    /H Include hexadecimal characters
    /V Remove any vowels from the output generated password.
</code
</pre>
