#!/usr/bin/env bash

set -x

my_dir="$(dirname "$(readlink -f "$0")")"

root_dir="$my_dir/../"
timestamp=$(date +%b%d_%Y.%H-%M-%S)
all_experiments_dir="$root_dir/experiments"

mkdir $all_experiments_dir 2> /dev/null

experiment_dir=$all_experiments_dir/experiment.$timestamp

# Use pbs_job to generate an experiment
pbs_job new $experiment_dir your_email@domain.com --no-append-timestamp # @todo Add PBS options here

# Append run experiment.sh line to task
run_exp_line="$my_dir/experiment"
sed -i "s|echo\s*\"Hi.*$|$run_exp_line|" $experiment_dir/task

# Run the job (if on a cluster, run job.qsub, otherwise run job.pbs)
$experiment_dir/job.pbs
