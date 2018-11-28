#!/bin/sh

if [ -d /opt/nec/ve/mpi/1.2.0 ]; then
	cmd="source /opt/nec/ve/mpi/1.2.0/bin/necmpivars.sh"
elif [ -d /opt/nec/ve/mpi/1.3.0 ]; then
	cmd="source /opt/nec/ve/mpi/1.3.0/bin/necmpivars.sh"
else
	cmd="source /opt/nec/ve/mpi/1.1.0/bin/necmpivars.sh"
fi

echo $cmd
$cmd
