#include <algorithm>
#include <set>
#include <list>
#include <iostream>

void dump( const std::string & label, const std::list< std::set< int > > & values )
{
    std::cout << label << std::endl;
    for( auto iter : values )
    {
        std::cout << "{ ";
        for( auto val : iter )
            std::cout << val << ", ";
        std::cout << "}, ";
    }
    std::cout << std::endl;
}

void combine( std::list< std::set< int > > & values )
{
    for( std::list< std::set< int > >::iterator iter = values.begin(); iter != values.end(); ++iter )
        for( std::list< std::set< int > >::iterator niter( iter ); ++niter != values.end(); )
            if( std::find_first_of( iter->begin(), iter->end(), niter->begin(), niter->end() ) != iter->end() )
            {
                iter->insert( niter->begin(), niter->end() );
                values.erase( niter );
                niter = iter;
            }
}

int main( int argc, char ** argv )
{
    std::list< std::set< int > > to_process = { { 1, 4 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 3, 5 } };
    dump( "Before", to_process );
    combine( to_process );
    dump( "After", to_process );

    return 0;
}