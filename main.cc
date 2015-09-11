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

#include "Parameters.hh"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    try
    {
        const Parameters& parameters = Parameters::parse(argc, argv);

        std::exit(0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(-1);
    }
}
