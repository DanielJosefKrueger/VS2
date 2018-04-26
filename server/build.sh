cc -c rdbase_svc.c
cc -c rdbase_sif.c
cc -c rdbase_srp.c
cc -c rdbase_xdr.c
cc -o rdbased rdbase_svc.o rdbase_sif.o rdbase_srp.o rdbase_xdr.o
