exports.normalizeSearchResult = ({ data: { podcasts } }) =>
  podcasts.map(({ title_original, id, thumbnail }) => ({
    id,
    thumbnail,
    title: title_original
  }));
