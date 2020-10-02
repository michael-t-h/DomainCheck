# DomainCheck

Unix-like utility for multithreaded mass DNS resolution, written in POSIX C using Linux kernel style guide.

This tool is for verifying that domain names can be resolved. Reads domains from standard input, writes verified domains to standard output.

Unlike other mass DNS resolution tools, this uses the standard system DNS resolver, not a custom UDP resolver. This is useful in environments where UDP is not available.
