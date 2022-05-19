package main

func updateWithVersion(id int, value int, version int) error {
	dto, err := dao.GetByID(id)
	if err != nil {

	}

	if dto.Version != version {
		// error
		return error
	}

	dto.Value = value
	err = dao.Update(id, dto)
	if err != nil {

	}

	return nil
}

func tryLock(lockID int, userID int) {
	dto, err := dao.GetLock(lockID)
	if dto.UserID != -1 {
		//locked
		if dto.UserID == userID {
			// self owned

		}

		// other owned
		return
	}

	lock()
}

func lock(lockID int, userID int) {
	for {
		select {
		case <-ch:
			err := updateWithVersion()
			if err != nil {

			} else {
				return //success
			}
		default:
			// continue
		}
	}
}

func unlock(lockID int, userID int) {
	dto, err := dao.GetLock(id)
	if err != nil {
	}
	if dto.UserID != userID {
		// locked
		return
	}

	dto.UserID = -1
	err = updateWithVersion(id, dto)

}
