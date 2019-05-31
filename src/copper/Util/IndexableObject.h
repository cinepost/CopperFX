#ifndef INDEXABLE_OBJECT_H
#define INDEXABLE_OBJECT_H

namespace copper {

typedef uint64_t obj_id_t;

class IndexableObject {
	public:
		IndexableObject();
		IndexableObject(const IndexableObject &iobject);

	private:
		static obj_id_t getNextID();

	private:
		obj_id_t _id;
};

}

#endif // INDEXABLE_OBJECT_H
