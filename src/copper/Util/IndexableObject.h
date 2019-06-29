#ifndef INDEXABLE_OBJECT_H
#define INDEXABLE_OBJECT_H

namespace copper {

typedef uint64_t obj_guid_t;

typedef obj_guid_t OpDataSocketGUID;
typedef obj_guid_t OpNodeGUID;

class IndexableObject {
	public:
		IndexableObject();
		IndexableObject(const IndexableObject &iobject);

	public:
		obj_guid_t GUID() const;

	private:
		static obj_guid_t getNextGUID();

	private:
		obj_guid_t _guid;
};

}

#endif // INDEXABLE_OBJECT_H
