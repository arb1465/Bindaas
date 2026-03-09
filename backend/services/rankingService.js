/**
 * Ranks places based on rating, popularity, and open status
 */

exports.rankPlaces = (places) => {
  return places
    .map((place) => {
      const rating = place.rating || 0;
      const totalRatings = place.total_ratings || 50; // fallback if not present

      // popularity weight
      const popularityScore = Math.log10(totalRatings + 1) * 0.3;

      // rating weight
      const ratingScore = rating * 0.7;

      let finalScore = ratingScore + popularityScore;

      // penalty if closed
      if (place.open_now === false) {
        finalScore -= 3;
      }

      return {
        ...place,
        relevance_score: parseFloat(finalScore.toFixed(2)),
      };
    })
    .sort((a, b) => b.relevance_score - a.relevance_score);
};