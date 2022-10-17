#include "movie.h"
#include <string>

movie::movie(string title, string director, string cast, double rating, int imbdId, int itemId)
:title(title),director(director),cast(cast),rating(rating),imbdId(imbdId),itemId(itemId),year(0)
{}