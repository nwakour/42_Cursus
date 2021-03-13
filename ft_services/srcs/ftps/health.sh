#!bin/bash
if ps | grep vsftpd | grep -vc grep; then exit 0; else exit 1 ; fi