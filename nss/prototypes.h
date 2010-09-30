/*
   prototypes.h - all functions exported by the NSS library

   Copyright (C) 2006 West Consulting
   Copyright (C) 2006, 2008, 2010 Arthur de Jong

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301 USA
*/

#ifndef NSS__PROTOTYPES_H
#define NSS__PROTOTYPES_H 1

#include "compat/nss_compat.h"

/*
   These are prototypes for functions exported from the ldap NSS module.
   For more complete definitions of these functions check the GLIBC
   documentation.

   Other services than those mentioned here are currently not implemented.

   These definitions partially came from examining the GLIBC source code
   as no complete documentation of the NSS interface is available.
   This however is a useful pointer:
   http://www.gnu.org/software/libc/manual/html_node/Name-Service-Switch.html
*/

/* flag to gloabally disable lookups (all _nss_ldap_*() functions will return
   NSS_STATUS_UNAVAIL */
extern int _nss_ldap_enablelookups;

/* aliases - mail aliases */
#ifdef HAVE_ALIASES_H
nss_status_t _nss_ldap_getaliasbyname_r(const char *name,struct aliasent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setaliasent(void);
nss_status_t _nss_ldap_getaliasent_r(struct aliasent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endaliasent(void);
#endif /* HAVE_ALIASES_H */

/* ethers - ethernet numbers */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_gethostton_r(const char *name,struct etherent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_getntohost_r(const struct ether_addr *addr,struct etherent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setetherent(int stayopen);
nss_status_t _nss_ldap_getetherent_r(struct etherent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endetherent(void);
#endif /* not HAVE_NSSWITCH_H */

/* group - groups of users */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getgrnam_r(const char *name,struct group *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_getgrgid_r(gid_t gid,struct group *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_initgroups_dyn(const char *user,gid_t group,long int *start,long int *size,gid_t **groupsp,long int limit,int *errnop);
nss_status_t _nss_ldap_setgrent(int stayopen);
nss_status_t _nss_ldap_getgrent_r(struct group *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endgrent(void);
#endif /* not HAVE_NSSWITCH_H */

/* hosts - host names and numbers */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_gethostbyname_r(const char *name,struct hostent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_gethostbyname2_r(const char *name,int af,struct hostent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_gethostbyaddr_r(const void *addr,socklen_t len,int af,struct hostent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_sethostent(int stayopen);
nss_status_t _nss_ldap_gethostent_r(struct hostent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_endhostent(void);
#endif /* not HAVE_NSSWITCH_H */

/* netgroup - list of host and users */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_setnetgrent(const char *group,struct __netgrent *result);
nss_status_t _nss_ldap_getnetgrent_r(struct __netgrent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endnetgrent(struct __netgrent *result);
#endif /* not HAVE_NSSWITCH_H */

/* networks - network names and numbers */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getnetbyname_r(const char *name,struct netent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_getnetbyaddr_r(uint32_t addr,int af,struct netent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_setnetent(int stayopen);
nss_status_t _nss_ldap_getnetent_r(struct netent *result,char *buffer,size_t buflen,int *errnop,int *h_errnop);
nss_status_t _nss_ldap_endnetent(void);
#endif /* not HAVE_NSSWITCH_H */

/* passwd - user database and passwords */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getpwnam_r(const char *name,struct passwd *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_getpwuid_r(uid_t uid,struct passwd *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setpwent(int stayopen);
nss_status_t _nss_ldap_getpwent_r(struct passwd *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endpwent(void);
#endif /* not HAVE_NSSWITCH_H */

/* protocols - network protocols */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getprotobyname_r(const char *name,struct protoent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_getprotobynumber_r(int number,struct protoent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setprotoent(int stayopen);
nss_status_t _nss_ldap_getprotoent_r(struct protoent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endprotoent(void);
#endif /* not HAVE_NSSWITCH_H */

/* rpc - remote procedure call names and numbers */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getrpcbyname_r(const char *name,struct rpcent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_getrpcbynumber_r(int number,struct rpcent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setrpcent(int stayopen);
nss_status_t _nss_ldap_getrpcent_r(struct rpcent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endrpcent(void);
#endif /* not HAVE_NSSWITCH_H */

/* services - network services */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getservbyname_r(const char *name,const char *protocol,struct servent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_getservbyport_r(int port,const char *protocol,struct servent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setservent(int stayopen);
nss_status_t _nss_ldap_getservent_r(struct servent *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endservent(void);
#endif /* not HAVE_NSSWITCH_H */

/* shadow - extended user information */
#ifndef HAVE_NSSWITCH_H
nss_status_t _nss_ldap_getspnam_r(const char *name,struct spwd *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_setspent(int stayopen);
nss_status_t _nss_ldap_getspent_r(struct spwd *result,char *buffer,size_t buflen,int *errnop);
nss_status_t _nss_ldap_endspent(void);
#endif /* not HAVE_NSSWITCH_H */

#endif /* not NSS__PROTOTYPES_H */
