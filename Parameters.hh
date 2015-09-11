#ifndef PARAMETERS_HH
#define PARAMETERS_HH
 
/*
 * (C) Copyright 2015 Enterome
 * 
 * This file is part of fastq-qual-stats.
 * 
 * fastq-qual-stats is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * fastq-qual-stats is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with fastq-qual-stats.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#include <vector>
#include <string>
#include <iostream>

struct Parameters
{
    std::vector<std::string> fastq_files;
    std::string stats_file;
    static Parameters parse(int argc, char* argv[]);
    static void check_file_is_readable(const std::string& filepath);
    static void check_file_is_writable(const std::string& filepath);
};

std::ostream& operator<<(std::ostream& os, const Parameters& parameters);

#endif // PARAMETERS_HH
