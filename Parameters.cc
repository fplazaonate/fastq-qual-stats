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
#include <fstream>
#include <stdexcept>
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

Parameters Parameters::parse(int argc, char* argv[])
{
    Parameters parameters;

    // Create options decription
    po::options_description opts_desc("Compute statistics on sequencing data");

    opts_desc.add_options()
        ("help,h", "print this help message")
        ("fastq-files,f", po::value<std::vector<std::string> >(&parameters.fastq_files)->multitoken(), "FASTQ files to analyze (Phred+33 qualities expected)")
        ("stats-file,s", po::value<std::string>(&parameters.stats_file)->required(), "Output file with statistics on sequencing data")
        ;

    // Retrieve and parse command line parameters
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, opts_desc), vm);

    // Print help
    if (argc == 1 || vm.count("help"))
    {
        std::cout << opts_desc << std::endl;
        std::exit(0);
    }

    BOOST_FOREACH(const std::string& fastq_file, parameters.fastq_files)
    {
        check_file_is_readable(fastq_file);
    }

    po::notify(vm);

    return (parameters);
}

void Parameters::check_file_is_readable(const std::string& filepath)
{
    std::ifstream ifs;
    ifs.open(filepath.c_str());

    if (ifs.good())
    {
        ifs.close();
    }
    else
    {
        throw (std::invalid_argument("error: " + filepath +
                    " cannot be opened. Check that the path is valid and that you have read permissions."));
    }
}

void Parameters::check_file_is_writable(const std::string& filepath)
{
    std::ofstream ofs;
    ofs.open(filepath.c_str());

    if (ofs.good())
    {
        ofs.close();
    }
    else
    {
        throw (std::invalid_argument("error: " + filepath +
                    " cannot be created. Check that the path is valid and that you have write permissions."));
    }
}


std::ostream& operator<<(std::ostream& os, const Parameters& parameters)
{
    os << "---------------------\n";
    os << "Parameters summary:\n\n";

    os << "--fastq-files = " << boost::algorithm::join(parameters.fastq_files, " ") << '\n';
    os << "--stats-file = " << parameters.stats_file << '\n';

    return os;
}

