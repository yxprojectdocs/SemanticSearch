void host_lookup(char *user_supplied_addr){
struct hostent *hp;
in_addr_t *addr;
char hostname[64];
in_addr_t inet_addr(const char *cp);

/*routine that ensures user_supplied_addr is in the right format for conversion */

validate_addr_form(user_supplied_addr);
addr = inet_addr(user_supplied_addr);
hp = gethostbyaddr( addr, sizeof(struct in_addr), AF_INET);
strcpy(hostname, hp->h_name);
}

// This code takes an IP address from the user and verifies that it is well formed. It then looks up the hostname and copies it into a buffer.
// This function allocates a buffer of 64 bytes to store the hostname.
// However, there is no guarantee that the hostname will not be larger than 64 bytes.
// If an attacker specifies an address which resolves to a very large hostname, then the function may overwrite sensitive data or even relinquish control flow to the attacker.
// Note that this example also contains an unchecked return value (CWE-252) that can lead to a NULL pointer dereference (CWE-476).