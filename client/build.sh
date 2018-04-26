cc -c rdbase_clnt.c
cc -c rdbase_cif.c
cc -c rdbase.c
cc -c rdbase_xdr.c
cc -o rdbase rdbase_clnt.o rdbase_cif.o rdbase.o rdbase_xdr.o
